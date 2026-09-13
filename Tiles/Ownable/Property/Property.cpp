#include "Property.h"
#include "../../../Player.h"

int Property::getNumHouses() {
    return numHouses;
}

int Property::getHouseCost() {
    return houseCost;
}

bool Property::hasHotel() {
    return propertyhasHotel;
}

int Property::getGroup() {
    return group;
}

//name, value, rent, houseCost, group
Property::Property(const char *name, int value, int rent, int houseCost, int group) {
    this->group = group;
    this->houseCost = houseCost;
    Ownable(name, value, rent);
};

Property::Property(const char *name, Deed *ptr)
    : Ownable(name, ptr->getCost(), ptr->getRent()),
    numHouses(0),
    propertyhasHotel(false)
{
    // Safely casts the Deed pointer to extract specialized variables
    TitleDeed *pointer = dynamic_cast<TitleDeed*>(ptr);
    if (pointer) {
        this->group = pointer->getColorGroup();
        this->houseCost = pointer->getHouseCost();
    } else {
        // Fallback to ensure stability if the cast fails
        this->group = -1;
        this->houseCost = 0;
    }
}

