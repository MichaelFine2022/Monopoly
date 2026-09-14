#include "Chance.h"
#include "../../Player.h"
#include "../../Interface.h"
#include "../../Decks/Deck.h"

Chance::Chance(Deck* deck) : deckPtr(deck) {
}

void Chance::handleLanding(Player* ptr, Interface* display) {
    Card drawnCard = deckPtr->drawCard();
    display->announceCard(ptr->getId(), drawnCard.text.c_str());
    drawnCard.action(ptr, display);
}