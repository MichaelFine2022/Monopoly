#include "Railroad.h"
#include "Ownable.h"

Railroad::Railroad(const char *name, int rent, int cost) {
    Ownable(name, rent, cost);
};
Railroad::Railroad(const char *name, Deed * deed) {
    Ownable(name, deed->getCost(), deed->getRent());
    this->deed = dynamic_cast<RailDeed*>(deed);
};
int Railroad::getRent(int numOwned) {
    return 0;
};
int Railroad::getRent(Player *player) {
    int numOwned = player->getNumRailroadsOwned();
    switch (numOwned) {
        case 0:
            return 0;
        case 1:
            return deed->getRentWithOne();
        case 2:
            return deed->getRentWithTwo();
        case 3:
            return deed->getRentWithThree();
        case 4:
            return deed->getRentWithFour();
        default:
            return deed->getRentWithHotel();
    }
};