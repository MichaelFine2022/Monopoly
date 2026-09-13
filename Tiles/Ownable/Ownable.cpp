#include "Ownable.h"
#include "../../Interface.h"

Player *Ownable::getOwner() {
    return owner;
}
int Ownable::getCost() {
    return cost;
}
int Ownable::getRent(Player* rollingPlayer) {
    return rent;
}
int Ownable::getMortgageValue() {
    return getCost() / 2;
}
bool Ownable::isMortgaged() {
    return mortgaged;
}
void Ownable::changeOwner(Player* newOwner) {
    this->owner = newOwner;
}
bool Ownable::hasOwner() {
    if (owner == nullptr) return false;
    else return true;
}

void Ownable::handleLanding(Player * landingPlayer, Interface* display) {
    //if it has an owner, pay rent
    //if not, ask if they want to buy it
    if (hasOwner()) {
        // Prevents the game from paying rent to yourself and ignore mortgaged properties
        if (owner != landingPlayer && !isMortgaged()) {
            int rentAmt = getRent(landingPlayer);
            landingPlayer->loseCash(rentAmt);
            owner->giveCash(rentAmt);
            display->announceRent(landingPlayer->getId(), owner->getId(), rentAmt);
        }
    }
    else {
        if (landingPlayer->canBuy(this)) {
            if (display->promptPurchase(landingPlayer->getId(), this->getName(), this->getCost())) {
                landingPlayer->buyProperty(this);
                this->changeOwner(landingPlayer);
            }
        }
    }
}
Ownable::Ownable(const char *name, int cost, int rent) : Space(name) {
    this->cost = cost;
    this->rent = rent;
    this->owner = nullptr;
}
Ownable::Ownable() {
    this->owner = nullptr;
}