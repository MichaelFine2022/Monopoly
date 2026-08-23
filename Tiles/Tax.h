#include "Space.h"

class Tax : public Space {
    private:
        int tax;
    public:
        Tax(char *name, int tax);
        Tax(char *name);
        int getTax();
};