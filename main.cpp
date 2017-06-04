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
    vector<string> do_swi{
        "4 4 8 8 ",
        "8 3 2 7 ",        
    };
    GameEngine ge(10,10,data,do_swi);
    ge.run();
}

