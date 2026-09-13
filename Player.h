#pragma once

#include <map>
#include <vector>

using namespace std;
class Space;
class Ownable;
class Player {
    private:
        Space** boardArray;
        int roll();
        signed int cash;
        int boardIndex;
        Space* space_ptr;
        void movePlayer(int roll);
        void handleLanding();
        signed int totalCash;
        bool isBankrupt;
        vector<Ownable *> properties;
        void updateTotalCash();
        unsigned int rollValue;
        
        bool inJail;
        int jailTurns;
        int doublesCount;
        bool lastRollWasDouble;
    public:
        std::map<int, int> ownedGroups;
        void takeTurn(Space **);
        bool isPlayerBankrupt() const;
        int getCash() const;
        void giveCash(int cash);
        void loseCash(int cash);
        void moveTo(Space *ptr);
        bool canBuy(Ownable *) const;
        void buyProperty(Ownable *);
        int getNumRailroadsOwned();
        int getNumUtilitiesOwned();
        int getLastRollValue();
        Player(Space **);
};