#include "../Space.h"
#include "Drawable.h"


#pragma once

class Chance : public Drawable {
    private:
        
    public:
        Chance();
        void handleLanding(Player* ptr, Interface* display) override;
        void drawCard();
};