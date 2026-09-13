#pragma once
#include <vector>
#include <string>

class Player;

class Interface {
    public:
        Interface();
        void introduction();
        unsigned int getNumPlayers();
        void declareVictory(std::vector<Player*>&);
        void interfaceIntroduction();
        
        // Interactive terminal methods
        void promptRoll(int playerId);
        bool promptPurchase(int playerId, const char* propertyName, int cost);
        void announceRoll(int playerId, int roll, const char* spaceName);
        void announceRent(int payerId, int receiverId, int amount);
};