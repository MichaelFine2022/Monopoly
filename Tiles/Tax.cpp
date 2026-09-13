#include "Tax.h"

Tax::Tax(const char *name) : Space(name) {
    this->tax = 200;
};

Tax::Tax(const char *name, int tax) : Space(name) {
    this->tax = tax;
}

int Tax::getTax() {
    return this->tax;
}