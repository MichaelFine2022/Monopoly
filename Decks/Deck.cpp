#include "Deck.h"
#include <chrono>

Deck::Deck() : currentIndex(0) {}

void Deck::addCard(const Card& card) {
    cards.push_back(card);
}

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    currentIndex = 0;
}

Card Deck::drawCard() {
    if (currentIndex >= cards.size()) {
        shuffle();
    }
    return cards[currentIndex++];
}