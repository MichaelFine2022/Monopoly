#include "../Ownable.h"
#include "../../../Decks/TitleDeed.h"

class Property : public Ownable {
    private:
        int numHouses;
        bool hasHotel;
        int group;
        int houseCost;
    public:
        int getNumHouses();
        int getHouseCost();
        bool hasHotel();
        int getGroup();
        // name, value, rent, houseCost, groupNum
        Property(char *name, int value, int rent, int houseCost, int group);
        Property(char *name, Deed *ptr);
};