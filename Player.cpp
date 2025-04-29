#include "game.h"
// #include "element-settings.h"
// #include "game.cpp"
#include <iostream>



double getTypeEffectiveness(const std::string& attackType, const std::string& targetType) {
    if (attackType == "Fire") {
        if (targetType == "Grass") return 1.5;
        if (targetType == "Water" || targetType == "Rock") return 0.5;
    }
    if (attackType == "Water") {
        if (targetType == "Fire" || targetType == "Rock") return 1.5;
        if (targetType == "Grass" || targetType == "Electric") return 0.5;
    }
    if (attackType == "Grass") {
        if (targetType == "Water" || targetType == "Rock") return 1.5;
        if (targetType == "Fire") return 0.5;
    }
    if (attackType == "Electric") {
        if (targetType == "Water") return 1.5;
        if (targetType == "Grass" || targetType == "Rock") return 0.5;
    }
    if (attackType == "Rock") {
        if (targetType == "Fire" || targetType == "Electric") return 1.5;
        if (targetType == "Water" || targetType == "Grass") return 0.5;
    }
    if (attackType == "Psychic") {
        if (targetType == "Electric" || targetType == "Rock") return 1.5;
        if (targetType == "Psychic") return 0.5;
    }

    return 1.0; // Default ไม่มีผลแพ้ชนะ
}



//------------Player----------
Player::Player(std::string name, std::vector<Monster> team,int currentMonster) // Constructor
    : name(name), team(team), currentMonster(currentMonster) {}

void Player::chooseAttack(int Dice, Player& opponent ) {  // choose attack
    // int Dice=0;
    Monster& attackerMon = team[currentMonster];
    Monster& defenderMon = opponent.team[opponent.currentMonster];

    std::cout << getTeam()[getCurrent()].getName() << " choose to Attack!\n";
    // std::cout <<"rolling Dice.. "<< std::endl;
    std::cout<< "your point is "<< Dice<<" Here're move(s) you can use"<< std::endl ;
    std::vector<Move> moves = getTeam()[getCurrent()].getmoves();

    //---------------------------------Display alvailable move
    int index =1;
    std::vector<Move> availableMoves = {};
    for (auto a : moves){
        if(a.getcost()<=Dice){
            std::cout<< index<< ". "<< a.getName()<< "type : "
                                    << a.getType()<< "damage : " 
                                    << a.getdamage()<< std::endl;
            availableMoves.push_back(a);
            index++;
        }
    }
    if(availableMoves.empty()){
        std::cout<<" There's no move(s) that can be use. Passing the turn";
        return;
    }
    //-------------------------------Choose one of the move-----------
    int choosen;
    std::cout <<std::endl <<"Enter the number of the move you want to use: ";
    std::cin>> choosen;
    choosen--;
    if(choosen>= 0 && choosen< availableMoves.size()){
        Move selectedMove = availableMoves[choosen];
        std::cout<< getName()<<"'s "<< getTeam()[getCurrent()].getName()<< " use " << selectedMove.getName() << "!" <<std::endl;
        
        int damage = selectedMove.getdamage();
        Monster& targetMonster = opponent.getTeam()[opponent.getCurrent()];
        double multiplier = getTypeEffectiveness(selectedMove.getType(), targetMonster.getType()); //check the element
        damage = static_cast<int>(damage * multiplier);

        if (multiplier > 1.0) {
            std::cout << "It's super effective!\n";
        } else if (multiplier < 1.0) {
            std::cout << "It's not very effective...\n";
        }

        int critical = rand() % 10;
        if (critical == 0) {
            damage=damage*2;
        }
        std::cout << "Critical Hit! \n";

        targetMonster.takeDamage(damage);
        
        if (!targetMonster.isAlive()) {
            std::cout << targetMonster.getName() << " fainted!\n";
            opponent.switchMonster();  // switch monster
        }
    }

}


void Player::switchMonster() {
    clearConsole();
    std::cout << "Choose a monster to switch to: "<< std::endl;
    int index =1;
    for (auto a : team) {
        std::cout<<index<<". "<<a.getName()<<" type : " << a.getHp()<< (!a.isAlive()? " - Fainted " : "")<<std::endl;
        index++;
        // const Monster& mon = team[i];
        // std::cout << i + 1 << ". " << mon->getName() 
        //           << " (HP: " << mon.getHp() 
        //           << (!mon.isAlive() ? " - Fainted" : "") << ")\n";
    }

    int choose;
    while (true) {
        std::cout << "Enter the number of the monster you want to switch to: ";
        std::cin >> choose;

        
        if (std::cin.fail() || choose< 1 || choose > (int)team.size()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        
        if (!team[choose - 1].isAlive()) {
            std::cout << team[choose - 1].getName() << " has fainted! Choose another.\n";
            continue;
        }

        break; 
    }

    currentMonster= choose - 1;
    std::cout << "Switched to " << team[currentMonster].getName() << "!\n";
}

