#include <Player.h>
#include "Deed.h"

class RailDeed : public Deed {
    public:
        RailDeed();
        RailDeed(int r1, int r2, int r3, int r4, int rt, int cost, int mortgageValue);
        int getRentWithOne();
        int getRentWithTwo();
        int getRentWithThree();
        int getRentWithFour();
        int getRentWithHotel();
        int getCost() override;
        int getMortgageValue();
        Player * getOwner();
        void changeOwner(Player *newOwner);
    private:
        int rentWithOne;
        int rentWithTwo;
        int rentWithThree;
        int rentWithFour;
        int rentWithHotel;
        int cost;
        int mortgageValue;
        Player *owner;
};