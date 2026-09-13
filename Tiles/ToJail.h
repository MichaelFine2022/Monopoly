#pragma once

#include "Space.h"
#include "Jail.h"
#include "../Player.h"


class ToJail : public Space {
    public:
        ToJail(Space *);
        void sendToJail(Player *player);
        Jail * getJail();
        void handleLanding(Player* ptr, Interface* display) override;
    private:
        Jail *jailPtr;

};