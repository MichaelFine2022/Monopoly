#include "Ownable.h"

class Utility : public Ownable {
    private:
    public:
        int getRent(int roll, int numOwned);
        int getRent();
        Utility(char *name);
};