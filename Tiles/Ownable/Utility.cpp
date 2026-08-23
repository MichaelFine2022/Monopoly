#include "Utility.h"

Utility::Utility(char *name) {
    Space(name);
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

