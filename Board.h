#pragma once

#include <map>

#include "Tiles/Ownable/Property/Property.h"
#include "Tiles/Ownable/Utility.h"

#include "Tiles/Space.h"

#include "Tiles/Drawable/CommunityChest.h"
#include "Tiles/Drawable/Chance.h"

#include "Tiles/Go.h"
#include "Tiles/Tax.h"
#include "Tiles/Jail.h"
#include "Tiles/FreeParking.h"
#include "Tiles/ToJail.h"

#include "Decks/Deck.h"


#include <iostream>

using namespace std;

class Deed;
class Board {
    public:
        Space *board[40] = {0};
        
        std::map<const char *, Deed*> propertyMap;
        Board();
        ~Board();
        void setup_US_spaces();
        Deck chanceDeck;
        Deck communityChestDeck;
};