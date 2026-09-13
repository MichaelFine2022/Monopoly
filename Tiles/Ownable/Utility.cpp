#include "Utility.h"

Utility::Utility(const char *name) : Ownable(name, 150, 0) {
}

int getRent(int roll, int numOwned) {
    if(numOwned == 1) {
        return 4 * roll;
    }
    else if(numOwned == 2) {
        return 10 * roll;
    }
    else {
        return -1;
    }
}

int Utility::getRent(Player* rollingPlayer) {
    if (!this->hasOwner() || rollingPlayer == nullptr) return 0;
    
    int roll = rollingPlayer->getLastRollValue();
    int numOwned = this->getOwner()->getNumUtilitiesOwned();
    
    if (numOwned == 1) return 4 * roll;
    if (numOwned == 2) return 10 * roll;
    return 0;
}

