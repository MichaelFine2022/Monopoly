#pragma once
#include "../Space.h"
#include "../../Player.h"

class Player;
class Ownable : public Space {
    private:
        Player *owner;
        int cost;
        bool mortgaged;
        int rent;
    public:
        Player *getOwner();
        bool hasOwner();
        void changeOwner(Player *newOwner);
        int getCost();
        virtual int getRent(Player* rollingPlayer = nullptr);
        int getMortgageValue();
        bool isMortgaged();
        void handleLanding(Player *ptr, Interface* display) override;
        void mortgageProperty();
        void unmortgageProperty();
        Ownable(const char *name, int cost, int rent);
        Ownable();
};