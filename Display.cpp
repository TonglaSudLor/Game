
// Fucking AI JoB!!!!!!!!!!!!!!!!!!!!!!!!!


#include <iostream>
#include <vector>
#include "game.h"
//max "_" 166
//max "_" 166
//max "1" 166
//max "2" 166
class BattleScreen {
private:
    int WIDTH = 166;
    int HEIGHT = 30;
    std::vector<std::string> screen;
public:
    BattleScreen() {
        screen = std::vector<std::string>(HEIGHT, std::string(WIDTH, ' '));
    }

    void clearScreen() {
        for (auto& line : screen) {
            line = std::string(WIDTH, ' ');
        }
    }

    void drawFrame(int x, int y, int boxWidth, int boxHeight) {
        // วาดกรอบ
        for (int i = 0; i < boxWidth; ++i) {
            screen[y][x + i] = '-';
            screen[y + boxHeight - 1][x + i] = '-';
        }
        for (int i = 0; i < boxHeight; ++i) {
            screen[y + i][x] = '|';
            screen[y + i][x + boxWidth - 1] = '|';
        }
        // มุม
        screen[y][x] = '+';
        screen[y][x + boxWidth - 1] = '+';
        screen[y + boxHeight - 1][x] = '+';
        screen[y + boxHeight - 1][x + boxWidth - 1] = '+';
    }

    void drawMonsterBox(int x, int y, std::string playerName, std::string monsterName, int currentHP, int maxHP) {
        int boxWidth = 40;
        int boxHeight = 5;
        drawFrame(x, y, boxWidth, boxHeight);
    
        std::string line1 = " Player: " + playerName;
        std::string line2 = " Monster: " + monsterName;
        std::string line3 = " HP: [";
    
        // HP bar
        int hpBarWidth = 20;
        int filled = (currentHP * hpBarWidth) / maxHP;
        for (int i = 0; i < hpBarWidth; ++i) {
            line3 += (i < filled) ? '#' : '-';
        }
        line3 += "] ";
    
        // >>> เพิ่มเลข HP ด้านหลัง <<< 
        line3 += std::to_string(currentHP) + "/" + std::to_string(maxHP);
    
        // วางข้อความ
        for (int i = 0; i < line1.size(); ++i) screen[y + 1][x + 1 + i] = line1[i];
        for (int i = 0; i < line2.size(); ++i) screen[y + 2][x + 1 + i] = line2[i];
        for (int i = 0; i < line3.size(); ++i) screen[y + 3][x + 1 + i] = line3[i];
    }
    

    void render() {
        for (const std::string& line : screen) {
            std::cout << line << '\n';
        }
    }

    // ฟังก์ชันอัปเดตข้อมูลเลย
    void updateBattleScreen(std::string botPlayer, std::string botMonster, int botHP, int botMaxHP,
                             std::string playerName, std::string playerMonster, int playerHP, int playerMaxHP) {
        clearScreen();

        drawMonsterBox(1, 1, botPlayer, botMonster, botHP, botMaxHP); // มุมซ้ายบน
        drawMonsterBox(WIDTH - 41, HEIGHT - 6, playerName, playerMonster, playerHP, playerMaxHP); // มุมขวาล่าง

        render();
    }
};

int main(){
    BattleScreen screen;

    screen.updateBattleScreen(
        "Bot", "Aquaril", 75, 100,  // ฝั่งศัตรู
        "Player", "Flamo", 50, 100  // ฝั่งเรา
    );
    
}