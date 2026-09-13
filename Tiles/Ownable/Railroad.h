#include "Ownable.h"
#include "../../Decks/RailDeed.h"

#pragma once

class Railroad : public Ownable {
    private:
        int baseRent;
        const char *name;
        RailDeed *deed;
    public:
        int getRent(int numOwned);
        int getRent(Player *);
        char *getName();
        //name, rent, cost
        Railroad(const char *name, int rent, int cost);
        Railroad(const char *name, Deed *deed);
};