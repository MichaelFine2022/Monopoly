#pragma once

#include "Drawable.h"



class Deck;

class Chance : public Drawable {
    private:
        Deck* deckPtr;
    public:
        Chance(Deck* deck);
        void handleLanding(Player* ptr, Interface* display) override;
};