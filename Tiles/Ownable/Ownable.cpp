#include "Ownable.h"

Player *Ownable::getOwner() {
    return owner;
}
int Ownable::getCost() {
    return cost;
}
int Ownable::getRent() {
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

void Ownable::handleLanding(Player * landingPlayer) {
    //if it has an owner, pay rent
    //if not, ask if they want to buy it
    if (hasOwner()) {
        int rent = getRent();
        landingPlayer->loseCash(rent);
    }
    else {
        if (landingPlayer->canBuy(this)) {
            //if they want to buy it
            if (true) {
                landingPlayer->buyProperty(this);
            } else {
                //return for now
                return;
            }
        }
        else {
            return;
        }
        //if they can buy it AT ALL, ask
        //if not say they can't buy it
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