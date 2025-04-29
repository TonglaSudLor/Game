#include "game.h"
#include "game.cpp"
#include <iostream>
#include <vector>
#include "Player.cpp"
#include "Monster.cpp"
#include "Move.cpp"
 int main(){
    Game myGame;
    myGame.start();

    while (true) {
        myGame.turnswitch();
        myGame.checkWin();
    }

    return 0;
 }

