#include "Tax.h"

Tax::Tax(char *name) {
    Space(name);
    this->tax = 200;
};

Tax::Tax(char *name, int tax) {
    Space(name);
    this->tax = tax;
}

int Tax::getTax() {
    return this->tax;
}