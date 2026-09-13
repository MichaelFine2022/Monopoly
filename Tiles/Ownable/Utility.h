#pragma once

#include "Ownable.h"


class Utility : public Ownable {
    private:
    public:
        int getRent(int roll, int numOwned);
        int getRent(Player* rollingPlayer) override;
        Utility(const char *name);
};