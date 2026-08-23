#include "Ownable.h"
#include "../../Decks/RailDeed.h"

class Railroad : public Ownable {
    private:
        int baseRent;
        char *name;
        RailDeed *deed;
    public:
        int getRent(int numOwned);
        int getRent(Player *);
        char *getName();
        //name, rent, cost
        Railroad(char *, int, int);
        Railroad(char *, Deed *);
};