#include "../Space.h"
#pragma once

class Player;
class Interface;
class Drawable : public Space {
    public:
        Drawable();
        void drawCard();
        void handleLanding(Player* ptr, Interface* display) override;
};