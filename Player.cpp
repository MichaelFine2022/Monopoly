#include "Player.h"
#include "Interface.h"
#include "Board.h"
#include "Tiles/Ownable/Railroad.h"
#include "Tiles/Ownable/Property/Property.h"

#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

Player::Player(Space **arr, int id) {
    this->id = id;
    this->cash = 1500;
    this->boardIndex = 0;
    this->boardArray = arr;
    this->space_ptr = arr[0];
    this->totalCash = cash;
    this->isBankrupt = false;
    this->rollValue = 0;
    this->inJail = false;
    this->jailTurns = 0;
    this->doublesCount = 0;
    this->lastRollWasDouble = false;
};

Player::~Player() {
    for (Ownable* prop : properties) {
        if (prop) {
            prop->changeOwner(nullptr);
        }
    }
    properties.clear();
}

void Player::printStatus() const {
    std::cout << "\n--- Player " << id << " Status ---\n"
                << "Cash: $" << cash << "\n"
                << "Properties Owned: " << properties.size() << "\n";
    for (Ownable* p : properties) {
        std::cout << " - " << p->getName() << "\n";
    }
    std::cout << "------------------------\n\n";
}

void Player::takeTurn(Space ** ptr, Interface* display) {
    do {
        if (inJail) {
            int rollResult = roll();
            if (lastRollWasDouble) {
                inJail = false;
                jailTurns = 0;
            }
            else {
                jailTurns++;
                if (jailTurns == 3) {
                    loseCash(50);
                    display->announceJailFine(this->id, 50);
                    inJail = false;
                    jailTurns = 0;
                    movePlayer(rollResult);
                }
                else {
                    return;
                }
            }
        }
        display->promptAction(this);
        int rollResult = roll();
        if (doublesCount == 3) {
            inJail = true;
            doublesCount = 0;
            moveTo((*ptr) + 9);
        }
        movePlayer(rollResult);
        display->announceRoll(this->id, rollResult, space_ptr->getName());
        handleLanding(display);
    } while (lastRollWasDouble && !inJail);
    
};

bool Player::isPlayerBankrupt() const {
    return this->isBankrupt;
}

int Player::roll() {
    
    unsigned int diceOne = (rand() % 6) + 1;
    unsigned int diceTwo = (rand() % 6) + 1;
    rollValue = diceOne + diceTwo;
    if (diceOne == diceTwo) {
        doublesCount++;
        lastRollWasDouble = true;
    }
    else {
        doublesCount = 0;
        lastRollWasDouble = false;
    }
    return diceOne + diceTwo;
}

int Player::getLastRollValue() {
    return this->rollValue;
}
int Player::getCash() const {
    return this->cash;
}

void Player::giveCash(int cash) {
    this->cash += cash;
    updateTotalCash();
}

void Player::loseCash(int cash) {
    this->cash -= cash;
    updateTotalCash();

    if (this->cash < 0) {
        this->isBankrupt = true;
        std::cout << "\n*** Player " << this->id << " has gone BANKRUPT! ***\n";
    }
}

void Player::sendToJail() {
    this->inJail = true;
    this->jailTurns = 0;
    this->doublesCount = 0;
    this->boardIndex = 10;
    this->space_ptr = boardArray[10];
}

void Player::movePlayer(int roll) {
    int newIndex = (boardIndex + roll) % 40;

    if (newIndex < boardIndex) {
        this->giveCash(200);
    }

    boardIndex = newIndex;
    this->space_ptr = boardArray[boardIndex];

}
void Player::handleLanding(Interface* display) {
    space_ptr->handleLanding(this, display);
}
void Player::moveTo(Space *ptr) {
    if (ptr == nullptr) return;
    this->space_ptr = ptr;
}
bool Player::canBuy(Ownable* property) const{
    if (totalCash >= property->getCost()) {
        return true;
    }
    else {
        return false;
    }
    return false;
}
void Player::updateTotalCash() {
    totalCash = cash;
    for (Ownable *ptr : properties) {
        totalCash += ptr->getMortgageValue();
    }
}
void Player::buyProperty(Ownable* property) {
    
    if (!canBuy(property)) return;
    int cost = property->getCost();
    properties.push_back(property);
    loseCash(cost);
    Property *ptr = dynamic_cast<Property*>(property);
    if (ptr) {
        ownedGroups[ptr->getGroup()]++;
    }
}
int Player::getNumRailroadsOwned() {
    int count = 0;
    for (Ownable *ptr : properties) {
        if (ptr) {
            Railroad *railptr = dynamic_cast<Railroad*>(ptr);
            if (railptr != nullptr) {
                count++;
            }
            
        }
    }
    return count;
}
int Player::getNumUtilitiesOwned() {
    int count = 0;
    for (Ownable *ptr : properties) {
        if (ptr) {
            Utility* utilptr = dynamic_cast<Utility*>(ptr);
            if (utilptr != nullptr) {
                count++;
            }
        }
    }
    return count;
}