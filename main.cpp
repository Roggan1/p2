/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 9. Mai 2017, 14:38
887 */

#include <cstdlib>
#include "GameEngine.h"
using namespace std;

/*
 * 
 */
int main() {
    vector<string> data{
        "##########",
        "####.....#",
        "###......#",
        "##.......#",
        "##########",
        "#..#.....#",
        "#..#.....#",
        "#..#.....#",
        "#..#.....#",
        "##########",
    };
    vector<string> specialTiles{
        "Character @ 5 5 ConsoleController 8 8",
        "Character % 2 3 StationaryController 3 4",
        "Greatsword 1 4",
        "Door 5 5 Lever 7 7",
        "Trap 6 6"        
    };
    GameEngine ge(10,10,data,specialTiles);
    ge.run();
}


void loadFromFile(string filename)
{
    
}
