#include "Drawable.h"
#include "Interface.h"
#include "Player.h"

Drawable::Drawable() {

};

void Drawable::handleLanding(Player* ptr, Interface* display) {
    display->announceCard(ptr->getId(), this->getName());
}