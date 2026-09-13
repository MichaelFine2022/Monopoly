#include "Interface.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <string>

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

void Interface::promptAction(Player* player) {
    std::string input;
    if (std::cin.peek() == '\n') std::cin.ignore();

    while (true) {
        std::cout << "\n-----------------------------------\n";
        std::cout << "Player " << player->getId() << "'s turn. Press Enter to roll or type 'status': ";
        std::getline(std::cin, input);

        if (input == "status") {
            player->printStatus();
        } else {
            break;
        }
    }
}

void Interface::announceJailFine(int playerId, int amount) {
    std::cout << "Player " << playerId << " paid a $" << amount << " fine to get out of jail.\n";
}

void Interface::announceTax(int playerId, const char* spaceName, int amount) {
    std::cout << "Player " << playerId << " paid $" << amount << " for " << spaceName << ".\n";
}

void Interface::announceCard(int playerId, const char* spaceName) {
    std::cout << "Player " << playerId << " drew a card from " << spaceName
                << ": (Safe space stub - no effect applied).\n";
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

