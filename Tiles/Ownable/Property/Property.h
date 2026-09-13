#include "../Ownable.h"
#include "../../../Decks/TitleDeed.h"

#pragma once

class Property : public Ownable {
    private:
        int numHouses;
        bool propertyhasHotel;
        int group;
        int houseCost;
    public:
        int getNumHouses();
        int getHouseCost();
        bool hasHotel();
        int getGroup();
        // name, value, rent, houseCost, groupNum
        Property(const char *name, int value, int rent, int houseCost, int group);
        Property(const char *name, Deed *deed);
};