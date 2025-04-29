#include "game.h"
//----------Monster--------
Monster::Monster(std::string name, std::string type, int HP, std::vector<Move> moves)  // Constructor
    :  baseObject(name, type), HP(HP), moves(moves){}

void Monster::takeDamage(int amount){ // subtrac damage from HP
    HP -= amount;
    if (HP < 0) HP = 0;
}
bool Monster::isAlive(){ // Check if monster is alive or not
 return HP>0;
}