#include <iostream>
#include "Player.h"
#include "Tiles/Space.h"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned int numPlayers;
    cout << "How many Players?" << endl;
    cin >> numPlayers;
    vector<Player *> players(numPlayers);
    
    

    //setup board
    Space * board[40];

    for (unsigned int i = 0; i < numPlayers; i++) {
        players.push_back(new Player(board));
    }

    //iterate through all players and have everyone take their turns
    unsigned int index = 0;
    while (numPlayers > 1) {
        
        //take each player's turn
        players[index]->takeTurn(board);

        //remove each player if bankrupt
        players.erase(remove_if(
            players.begin(), players.end(),
            [](const Player* player){
                return player->isPlayerBankrupt() == true;
            }
        ), players.end());

        //get num player in game
        if ((unsigned int) numPlayers != ((unsigned int) players.size())) {
            numPlayers = players.size();
        }
        else {
            index++;
        }

        if (index >= numPlayers) {
            index = 0;
        }
    }
    cout << "Player Victory";
    delete board;
    return 0;
}

