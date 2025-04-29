#include "game.h"
#include <iostream>
//-----------Move--------
Move::Move(std::string name, std::string type, int cost, int damage) // Constructor
    : baseObject(name, type), cost(cost), damage(damage) {}

void Move::use(std::string attacker, std::string target) {
    std::cout << attacker << " uses " << getName() << " on " << target << "!\n";
}