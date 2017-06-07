/* 
 * File:   GameEngine.h
 * Author: fs
 *
 * Created on 9. Mai 2017, 16:56
 */

#ifndef GAMEENGINE_H
#define	GAMEENGINE_H
#include "DungeonMap.h"
#include "ConsoleController.h"

class GameEngine {
public:
    GameEngine(int height, int width, const vector<string>& data, const vector<string>& do_swi);
    virtual ~GameEngine();
    
    bool finished();
    void turn();
    void run();
    void printMenue();
    void Menue(Character* c);
    
private:
    vector<Character*> m_Chars;
    DungeonMap m_map;
    vector<Controller*> m_Controllers;
    int m_counter;
};

#endif	/* GAMEENGINE_H */

