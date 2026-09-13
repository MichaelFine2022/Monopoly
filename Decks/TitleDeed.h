#include "../Player.h"
#include "Deed.h"

#pragma once

class TitleDeed : public Deed {
    public:
        TitleDeed(int, int, int, int, int, int, int, int, int, int, int);
        int getRentWithColorSet();
        int getRentWithOne();
        int getRentWithTwo();
        int getRentWithThree();
        int getRentWithFour();
        int getRentWithHotel();
        int getHouseCost();
        int getCost() override;
        int getMortgageValue();
        int getColorGroup();
        Player * getOwner();
        void changeOwner(Player *newOwner);
    private:
        
        int rentWithColorSet;
        int rentWithOne;
        int rentWithTwo;
        int rentWithThree;
        int rentWithFour;
        int rentWithHotel;
        int houseCost;
        int mortgageValue;
        int colorGroup;
        Player *owner;
};