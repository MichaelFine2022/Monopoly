#include "ToJail.h"
#include "Jail.h"
#include "../Player.h"

ToJail::ToJail(Space *jailPtr) {
    Space("Go To Jail");
    this->jailPtr = (Jail *)jailPtr;
};
void ToJail::sendToJail(Player *player) {
    player->moveTo(this->jailPtr);
}
