#include "Player.h"
#include "Board.h"
#include "Railroad.h"

#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

Player::Player(Space **arr) {
    this->cash = 1500;
    this->boardIndex = 0;
    this->space_ptr = *arr;
    this->totalCash = cash;
    this->isBankrupt = false;
    this->rollValue = 0;
    this->inJail = false;
    this->jailTurns = 0;
    this->doublesCount = 0;
    this->lastRollWasDouble = false;
};

void Player::takeTurn(Space ** ptr) {
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
                    inJail = false;
                    jailTurns = 0;
                    movePlayer(rollResult);
                }
                else {
                    return;
                }
            }
        }
        int rollResult = roll();
        if (doublesCount == 3) {
            inJail = true;
            doublesCount = 0;
            moveTo((*ptr) + 9);
        }
        movePlayer(rollResult);
        handleLanding();
    } while (lastRollWasDouble && !inJail);
    
};

bool Player::isPlayerBankrupt() const{
    return this->isBankrupt;
}

int Player::roll() {
    srand(time(0));
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
}

void Player::movePlayer(int roll) {
    for (int i = 0; i < roll; i++) {
        boardIndex++;
        
        if (boardIndex == 40) {
            this->cash += 200;
            boardIndex = 0;
            this->space_ptr = space_ptr - 39;
        }
        else {
            this->space_ptr = space_ptr + 1;
        }
    }
}
void Player::handleLanding() {
    space_ptr->handleLanding(this);
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