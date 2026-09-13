#include "Chance.h"
#include "../../Player.h"
#include "../../Interface.h"
#include <cstdlib>


void Chance::drawCard() {

}
Chance::Chance() {

}
void Chance::handleLanding(Player* ptr, Interface* display) {
    int cardDrawn = rand() % 3;
    
    if (cardDrawn == 0) {
        display->announceCard(ptr->getId(), "Chance: Bank pays you a dividend of $50!");
        ptr->giveCash(50);
    } else if (cardDrawn == 1) {
        display->announceCard(ptr->getId(), "Chance: Poor tax! Pay $15.");
        ptr->loseCash(15);
    } else {
        display->announceCard(ptr->getId(), "Chance: Go directly to Jail!");
        ptr->sendToJail();
    }
}