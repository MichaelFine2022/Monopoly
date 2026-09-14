#pragma once
#include <string>
#include <functional>
class Player;
class Interface;

struct Card {
    std::string text;
    std::function<void(Player*, Interface*)> action;
};