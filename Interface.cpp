#include "Interface.h"
#include <iostream>
#include "Player.h"
#include <vector>

using namespace std;

Interface::Interface() {
    cout << "Welcome to Monopoly" << endl;
}

unsigned int Interface::getNumPlayers() {
    unsigned int numPlayers;
    cout << "How many Players?" << endl;
    cin >> numPlayers;
    return numPlayers;
    
}

void Interface::declareVictory(vector<Player*>& vect) {
    return;
}

void Interface::interfaceIntroduction() {
    return;
}

