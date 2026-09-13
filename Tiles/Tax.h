#pragma once

#include "Space.h"

class Tax : public Space {
    private:
        int tax;
    public:
        Tax(const char *name, int tax);
        Tax(const char *name);
        int getTax();
        void handleLanding(Player* ptr, Interface* display) override;
};