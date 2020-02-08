#include <iostream>
#include <fstream>
using namespace std;

void saveGame(int x, int y, int health, int attack, int xp){
    ofstream f("latestSaveFile.txt");
    f << x;
    f << ".";
    f << y;
    f << ".";
    f << health;
    f << ".";
    f << attack;
    f << ".";
    f << xp;
    f.close();
}
