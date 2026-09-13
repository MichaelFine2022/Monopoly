#include <iostream>
#include <vector>
#include <algorithm>

#include "Interface.h"
#include "Tiles/Space.h"

#include "Player.h"
#include "Board.h"
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    Interface *display = new Interface();
    signed int numPlayers = display->getNumPlayers();
    vector<Player *> players(numPlayers);
    
    //setup board
    Board *board = new Board();

    for (unsigned int i = 0; i < (unsigned int) numPlayers; i++) {
        players.push_back(new Player(board->board));
    }

    //iterate through all players and have everyone take their turns
    unsigned int index = 0;
    while (numPlayers > 1) {
        
        //take each player's turn
        players[index]->takeTurn(board->board);

        //remove each player if bankrupt
        players.erase(remove_if(
            players.begin(), players.end(),
            [](const Player* player){
                return player->isPlayerBankrupt();
            }
        ), players.end());

        //get number of players in game
        if ((unsigned int) numPlayers != ((unsigned int) players.size())) {
            numPlayers = players.size();
        }
        else {
            index++;
        }

        if ((unsigned int) index >= (unsigned int) numPlayers) {
            index = 0;
        }
    }
    display->declareVictory(players);
    
    delete board;
    delete display;
    for (Player* p : players) {
        delete p;
    }
    return 0;
}

