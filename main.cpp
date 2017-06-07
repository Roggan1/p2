/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 9. Mai 2017, 14:38
887 */

#include <cstdlib>
#include "GameEngine.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 * 
 */
void loadFromFile(string filename);
int main() {
    loadFromFile("level1.txt");
    /*
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
        "Door 4 4 Lever 7 7",
        "Trap 6 6"        
    };
    GameEngine ge(10,10,data,specialTiles);
    ge.run();
     */
}


void loadFromFile(string filename)
{
     vector<string> data;
    vector<string> do_swi;
    ifstream ifs;
    string line;

    ifs.open(filename, ios::in);

    int width;
    int height;
    ifs >> width >> height;
   
    getline(ifs, line);
    cout << width << " " << height << endl;

    for (int i = 0; i < height ; i++) {
        getline(ifs, line);
        data.push_back(line);
        cout << line << endl;
    }

    while (!ifs.eof()) {
        getline(ifs, line);
        cout << line << endl;
        do_swi.push_back(line);
    }

    ifs.close();

    GameEngine ge(height, width, data, do_swi);
ge.run();
}
