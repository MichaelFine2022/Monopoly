#pragma once

#include <vector>

class Player;
class Interface {
    private:
    public:
        Interface();
        void introduction();
        unsigned int getNumPlayers();
        void declareVictory(std::vector<Player*>&);
        void interfaceIntroduction();
};