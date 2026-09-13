#include "../Space.h"
#include "Drawable.h"
#pragma once


class CommunityChest : public Drawable {
    private:
        
    public:
        CommunityChest();
        void handleLanding(Player* ptr, Interface* display) override;
        void drawCard();
};