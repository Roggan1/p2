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
        "44 88 ",
        "83 27 ",        
    };
    GameEngine ge(10,10,data,do_swi);
    ge.run();
}

