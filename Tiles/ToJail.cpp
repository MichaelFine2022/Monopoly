#include "ToJail.h"
#include "Jail.h"
#include "../Player.h"
#include "../../Interface.h"

ToJail::ToJail(Space *jailPtr) {
    Space("Go To Jail");
    this->jailPtr = (Jail *)jailPtr;
};
void ToJail::sendToJail(Player *player) {
    player->moveTo(this->jailPtr);
}

void ToJail::handleLanding(Player* ptr, Interface* display) {
    display->announceCard(ptr->getId(), "Go To Jail");
    ptr->sendToJail();
}
