#include "Property.h"
#include "../../../Player.h"
#include "Player.h"

int Property::getNumHouses() {
    return numHouses;
}

int Property::getHouseCost() {
    return houseCost;
}

bool Property::hasHotel() {
    return hasHotel;
}

int Property::getGroup() {
    return group;
}

//name, value, rent, houseCost, group
Property::Property(char *name, int value, int rent, int houseCost, int group) {
    this->group = group;
    this->houseCost = houseCost;
    Ownable(name, value, rent);
};

Property::Property(char *name, Deed *ptr) {
    TitleDeed *pointer = (TitleDeed *)ptr;
    Ownable(name, 5, 4);
}

