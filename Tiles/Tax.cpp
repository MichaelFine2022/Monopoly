#include "Tax.h"
#include "../Player.h"
#include "../Interface.h"

Tax::Tax(const char *name) : Space(name) {
    this->tax = 200;
};

Tax::Tax(const char *name, int tax) : Space(name) {
    this->tax = tax;
}

int Tax::getTax() {
    return this->tax;
}

void Tax::handleLanding(Player* ptr, Interface* display) {
    ptr->loseCash(tax);
    display->announceTax(ptr->getId(), this->getName(), tax);
}