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

void Interface::promptRoll(int playerId) {
    std::cout << "\n-----------------------------------\n";
    std::cout << "Player " << playerId << "'s turn. Press Enter to roll...";
    
    // Clear previous inputs
    if (std::cin.peek() == '\n') std::cin.ignore();
    std::cin.get();
}

bool Interface::promptPurchase(int playerId, const char* propertyName, int cost) {
    std::cout << "Player " << playerId << ", do you want to buy "
                << propertyName << " for $" << cost << "? (y/n): ";
    char choice;
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

void Interface::announceRoll(int playerId, int roll, const char* spaceName) {
    std::cout << "Player " << playerId << " rolled a " << roll
                << " and landed on " << spaceName << ".\n";
}

void Interface::announceRent(int payerId, int receiverId, int amount) {
    std::cout << "Player " << payerId << " paid $" << amount
                << " in rent to Player " << receiverId << ".\n";
}

