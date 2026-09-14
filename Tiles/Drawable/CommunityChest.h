#pragma once
#include "Drawable.h"


class Deck;
class CommunityChest : public Drawable {
    private:
        Deck* deckPtr;
    public:
        CommunityChest(Deck* deck);
        void handleLanding(Player* ptr, Interface* display) override;
};