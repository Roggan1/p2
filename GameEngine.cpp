/* 
 * File:   GameEngine.cpp
 * Author: fs
 * 
 * Created on 9. Mai 2017, 16:56
 */



#include "GameEngine.h"
#include <sstream>

GameEngine::GameEngine(int height, int width, const vector<string>& data, const vector<string>& do_swi) : m_map(height, width, data) {
    m_Chars.push_back(new Character('+',5,5));
    m_Controllers.push_back(new ConsoleController(m_Chars[0]));
    
    Position tmp;
    tmp.heigth=6;
    tmp.width=6;
    m_map.place(tmp,m_Chars[0]);
    
    //Interpreter Door/Switch
    stringstream ss;
    int Sx = 0;
    int Sy = 0;
    int Dx = 0;
    int Dy = 0;
    
    for(int i = 0; i< do_swi.size(); i++)
    {
        ss.str(do_swi[i]);
        ss >> Dx >> Dy >> Sx >> Sy;
        ss.clear();
        Position D,S;                   //string-stream
        D.heigth=Dx;
        D.width=Dy;
        S.heigth=Sx;
        S.width=Sy;
        
        m_map.placeDoor_Switch(D,S);
    }
}

GameEngine::~GameEngine() {
    for(int i = 0; i< m_Chars.size(); i++)
    {
        delete m_Chars[i];
    }
    for(int i = 0; i< m_Controllers.size(); i++)
    {
        delete m_Controllers[i];
    }
    
}

bool GameEngine::finished(){
    return false;
}

void GameEngine::turn(){
    for(int i = 0; i < m_Chars.size(); i++){
        int dir = m_Chars.at(i)->move(); //Abrufen der Bewegungsrichtung
        Position tmp = m_map.findCharacter(m_Chars.at(i)); //Speichern der Position des Characters
        Tile* before = m_map.findTile(tmp); //Speichern des Tiles for dem Spielzug
        
         switch (dir) { //Bewegen der Spielfigur
        case 3:
            tmp.heigth++;
            tmp.width++;
     
            break;
        case 2: 
            tmp.heigth++;
           
            break;
        case 1: 
            tmp.heigth++;
            tmp.width--;
          
            break;
        case 6: 
            tmp.width++;
            
            break;
        case 5: 
            break;
        case 4: 
            tmp.width--;
           
            break;
        case 9: 
            tmp.heigth--;
            tmp.width++;
            
            break;
        case 8: 
            tmp.heigth--;
            
            break;
        case 7: 
            tmp.heigth--;
            tmp.width--;
            
            break;
        default: ;
    }
       Tile* after=m_map.findTile(tmp); //Speichern des Tiles nach dem Zug
       before->onLeave(after);
    }
}

void GameEngine::run(){
    while(!finished()){
        m_Chars[0]->showInfo();
        m_map.print();
        turn();
    }
}