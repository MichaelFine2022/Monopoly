#include "CommunityChest.h"
#include "../../Player.h"
#include "../../Interface.h"
#include "../../Decks/Deck.h"


CommunityChest::CommunityChest(Deck* deck) : deckPtr(deck) {
}

void CommunityChest::handleLanding(Player* ptr, Interface* display) {
    Card drawnCard = deckPtr->drawCard();
    display->announceCard(ptr->getId(), drawnCard.text.c_str());
    drawnCard.action(ptr, display);
}