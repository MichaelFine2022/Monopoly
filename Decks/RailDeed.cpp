#include "RailDeed.h"

RailDeed::RailDeed() {
    this->rentWithOne = 0;
    this->rentWithTwo = 0;
    this->rentWithThree = 0;
    this->rentWithFour = 0;
    this->rentWithHotel = 0;
    this->cost = 0;
    this->mortgageValue = 0;
    this->owner = 0;
}
RailDeed::RailDeed(int r1, int r2, int r3, int r4, int rt, int cost, int mortgageValue) {
    this->rentWithOne = r1;
    this->rentWithTwo = r2;
    this->rentWithThree = r3;
    this->rentWithFour = r4;
    this->rentWithHotel = rt;
    this->cost = cost;
    this->mortgageValue = mortgageValue;
    this->owner = 0;
}

int RailDeed::getRentWithOne() {
    return rentWithOne;
}
int RailDeed::getRentWithTwo() {
    return rentWithTwo;
}
int RailDeed::getRentWithThree() {
    return rentWithThree;
}
int RailDeed::getRentWithFour() {
    return rentWithFour;
}
int RailDeed::getRentWithHotel() {
    return rentWithHotel;
}
int RailDeed::getCost() {
    return cost;
}
int RailDeed::getMortgageValue() {
    return mortgageValue;
}
Player *RailDeed::getOwner() {
    return owner;
}
void RailDeed::changeOwner(Player *newOwner) {
    this->owner = newOwner;
}