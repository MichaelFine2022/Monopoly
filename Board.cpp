#include "Board.h"
#include "Tiles/Ownable/Railroad.h"
Board::Board() {
    cout <<"Board Constructor called." << endl;
    //Populate the decks using C++ lambdas for the card effects
    chanceDeck.addCard({
        "Bank pays you dividend of $50",
        [](Player* p, Interface*) { p->giveCash(50); }
    });
    
    chanceDeck.addCard({
        "Go directly to Jail",
        [](Player* p, Interface*) { p->sendToJail(); }
    });

    communityChestDeck.addCard({
        "Doctor's fee. Pay $50",
        [](Player* p, Interface*) { p->loseCash(50); }
    });

    //Shuffle the loaded decks
    chanceDeck.shuffle();
    communityChestDeck.shuffle();
    setup_US_spaces();
};

Board::~Board() {
    for (Space * ptr: board) {
        if (ptr) {
            delete ptr;
        }
    }
    for (auto const& pair : propertyMap) {
        delete pair.second;
    }
    propertyMap.clear();
}
void Board::setup_US_spaces() {
    board[0] = new Go();
    propertyMap["Mediterranean Avenue"] = new TitleDeed(2,4,10, 30, 90, 160, 250, 50, 60, 30, 1);
    board[1] = new Property("Mediterranean Avenue", propertyMap["Mediterranean Avenue"]);
    board[2] = new CommunityChest(&communityChestDeck);
    propertyMap["Baltic Avenue"] = new TitleDeed(4, 8, 20, 60, 180, 320, 450, 50, 60, 30, 1);
    board[3] = new Property("Baltic Avenue", propertyMap["Baltic Avenue"]);

    board[4] = new Tax("Income Tax", 200);

    propertyMap["Reading Railroad"] = new RailDeed(25, 50, 100, 200, 400, 200, 100);
    board[5] = new Railroad("Reading Railroad", propertyMap["Reading Railroad"]);

    propertyMap["Oriental Avenue"] = new TitleDeed(6, 12, 30, 90, 270, 400, 550, 50, 100, 50, 2);
    board[6] = new Property("Oriental Avenue", propertyMap["Oriental Avenue"]);

    board[7] = new Chance(&chanceDeck);

    propertyMap["Vermont Avenue"] = new TitleDeed(6, 12, 30, 90, 270, 400, 550, 50, 100, 50, 2);
    board[8] = new Property("Vermont Avenue", propertyMap["Vermont Avenue"]);

    propertyMap["Connecticut Avenue"] = new TitleDeed(8, 16, 40, 100, 300, 450, 600, 50, 120, 60, 2);
    board[9] = new Property("Connecticut Avenue", propertyMap["Connecticut Avenue"]);
        
    board[10] = new Jail();

    propertyMap["St. Charles Place"] = new TitleDeed(10, 20, 50, 150, 450, 625, 750, 100, 140, 70, 3);
    board[11] = new Property("St. Charles Place", propertyMap["St. Charles Place"]);

    board[12] = new Utility("Electric Company");
    propertyMap["States Avenue"] = new TitleDeed(10, 20, 50, 150, 450, 625, 750, 100, 140, 70, 3);
    board[13] = new Property("States Avenue", propertyMap["States Avenue"]);
        
    propertyMap["Virginia Avenue"] = new TitleDeed(12, 24, 60, 180, 500, 700, 900, 100, 160, 80, 3);
    board[14] = new Property("Virginia Avenue", propertyMap["Virginia Avenue"]);
    
    propertyMap["Pennsylvania Railroad"] = new RailDeed(25, 50, 100, 200, 400, 200, 100);
    board[15] = new Railroad("Pennsylvania Railroad", propertyMap["Pennsylvania Railroad"]);
        
    propertyMap["St. James Place"] = new TitleDeed(14, 28, 70, 200, 550, 750, 950, 100, 180, 90, 4);
    board[16] = new Property("St. James Place", propertyMap["St. James Place"]);

    board[17] = new CommunityChest(&communityChestDeck);

    propertyMap["Tennessee Avenue"] = new TitleDeed(14, 28, 70, 200, 550, 750, 950, 100, 180, 90, 4);
    board[18] = new Property("Tennessee Avenue", propertyMap["Tennessee Avenue"]);
    
    propertyMap["New York Avenue"] = new TitleDeed(16, 32, 80, 220, 600, 800, 1000, 100, 200, 100, 4);
    board[19] = new Property("New York Avenue", propertyMap["New York Avenue"]);
    
    board[20] = new FreeParking();

    propertyMap["Kentucky Avenue"] = new TitleDeed(18, 36, 90, 250, 700, 875, 1050, 150, 220, 110, 5);
    board[21] = new Property("Kentucky Avenue", propertyMap["Kentucky Avenue"]);
    
    board[22] = new Chance(&chanceDeck);

    propertyMap["Indiana Avenue"] = new TitleDeed(18, 36, 90, 250, 700, 875, 1050, 150, 220, 110, 5);
    board[23] = new Property("Indiana Avenue", propertyMap["Indiana Avenue"]);
    
    propertyMap["Illinois Avenue"] = new TitleDeed(20, 40, 100, 300, 750, 925, 1100, 150, 240, 120, 5);
    board[24] = new Property("Illinois Avenue", propertyMap["Illinois Avenue"]);
    
    propertyMap["B. & O. Railroad"] = new RailDeed(25, 50, 100, 200, 400, 200, 100);
    board[25] = new Railroad("B. & O. Railroad", propertyMap["B. & O. Railroad"]);

    propertyMap["Atlantic Avenue"] = new TitleDeed(22, 44, 110, 330, 800, 975, 1150, 150, 260, 130, 6);
    board[26] = new Property("Atlantic Avenue", propertyMap["Atlantic Avenue"]);

    propertyMap["Ventnor Avenue"] = new TitleDeed(22, 44, 110, 330, 800, 975, 1150, 150, 260, 130, 6);
    board[27] = new Property("Ventnor Avenue", propertyMap["Ventnor Avenue"]);

    board[28] = new Utility("Water Works");

    propertyMap["Marvin Gardens"] = new TitleDeed(24, 48, 120, 360, 850, 1025, 1200, 150, 280, 140, 6);
    board[29] = new Property("Marvin Gardens", propertyMap["Marvin Gardens"]);

    board[30] = new ToJail((board[10]));

    propertyMap["Pacific Avenue"] = new TitleDeed(26, 52, 130, 390, 900, 1100, 1275, 200, 300, 150, 7);
    board[31] = new Property("Pacific Avenue", propertyMap["Pacific Avenue"]);
    
    propertyMap["North Carolina Avenue"] = new TitleDeed(26, 52, 130, 390, 900, 1100, 1275, 200, 300, 150, 7);
    board[32] = new Property("North Carolina Avenue", propertyMap["North Carolina Avenue"]);
    
    board[33] = new CommunityChest(&communityChestDeck);

    propertyMap["Pennsylvania Avenue"] = new TitleDeed(28, 56, 150, 450, 1000, 1200, 1400, 200, 320, 160, 7);
    board[34] = new Property("Pennsylvania Avenue", propertyMap["Pennsylvania Avenue"]);

    propertyMap["Short Line"] = new RailDeed(25, 50, 100, 200, 400, 200, 100);
    board[35] = new Railroad("Short Line", propertyMap["Short Line"]);
    
    board[36] = new Chance(&chanceDeck);

    propertyMap["Park Place"] = new TitleDeed(35, 70, 175, 500, 1100, 1300, 1500, 200, 350, 175, 8);
    board[37] = new Property("Park Place", propertyMap["Park Place"]);

    board[38] = new Tax("Luxury Tax", 200);
    
    propertyMap["Boardwalk"] = new TitleDeed(50, 100, 200, 600, 1400, 1700, 2000, 200, 400, 200, 8);
    board[39] = new Property("Boardwalk", propertyMap["Boardwalk"]);
};

