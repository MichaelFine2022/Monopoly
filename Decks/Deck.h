#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Deck {
    private:
        std::vector<Card> cards;
        size_t currentIndex;

    public:
        Deck();
        void addCard(const Card& card);
        void shuffle();
        Card drawCard();
};