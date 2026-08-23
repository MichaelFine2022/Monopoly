#include "TitleDeed.h"
#include "Deed.h"

TitleDeed::TitleDeed(int r1, int r2, int r3, int r4, int r5, int r6, int r7, int r8, int r9, int r10, int r11) {
    this->rentWithColorSet = r2;
    this->rentWithOne = r3;
    this->rentWithTwo = r4;
    this->rentWithThree = r5;
    this->rentWithFour = r6;
    this->rentWithHotel = r7;
    this->houseCost = r8;
    this->cost = r9;
    this->mortgageValue = r10;
    this->colorGroup = r11;
    this->owner = 0;
}
int TitleDeed::getRentWithColorSet() {
    return rentWithColorSet;
}
int TitleDeed::getRentWithOne() {
    return rentWithOne;
}
int TitleDeed::getRentWithTwo() {
    return rentWithTwo;
}
int TitleDeed::getRentWithThree() {
    return rentWithThree;
}
int TitleDeed::getRentWithFour() {
    return rentWithFour;
}
int TitleDeed::getRentWithHotel() {
    return rentWithHotel;
}
int TitleDeed::getHouseCost() {
    return houseCost;
}
int Deed::getCost() {
    return cost;
}
int TitleDeed::getMortgageValue() {
    return mortgageValue;
}
int TitleDeed::getColorGroup() {
    return colorGroup;
}
Player *TitleDeed::getOwner() {
    return owner;
}
void TitleDeed::changeOwner(Player *newOwner) {
    this->owner = newOwner;
}