/* 
 * File:   GameEngine.cpp
 * Author: fs
 * 
 * Created on 9. Mai 2017, 16:56
 */



#include "GameEngine.h"
#include <sstream>
#include "StationaryController.h"
#include "Item.h"

GameEngine::GameEngine(int height, int width, const vector<string>& data, const vector<string>& specialTiles) : m_map(height, width, data) {
    
    stringstream ss;
    
    string cmd1;
    string cmd2;
    char c;
    
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int param4 = 0;
    
    for(int i = 0; i< specialTiles.size(); i++)
    {
        ss.str(specialTiles[i]);
        ss >> cmd1;
        if (cmd1=="Character")
        {
                ss>> c >> param1 >> param2 >> cmd2 >> param3 >> param4;
                ss.clear();
                m_Chars.push_back(new Character(c,param1,param2));
                if(cmd2=="ConsoleController"){
                m_Controllers.push_back(new ConsoleController(m_Chars[m_Chars.size()-1]));
                }else{
                m_Controllers.push_back(new StationaryController(m_Chars[m_Chars.size()-1])); 
                }
                Position tmp;
                tmp.heigth=param3;
                tmp.width=param4;
                m_map.place(tmp,m_Chars[m_Chars.size()-1]);
        }else if(cmd1=="ArmingSword"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new ArmingSword);
        }else if(cmd1=="Greatsword"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new GreatSword);
        }else if(cmd1=="Club"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new Club);
        }else if(cmd1=="RapierOrDagger"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new RapierOrDagger);
        }else if(cmd1=="Gambeson"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new Gambeson);
        }else if(cmd1=="MailArmour"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new MailArmour);
        }else if(cmd1=="Shield"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new Shield);
        }else if(cmd1=="FullPlateArmour"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeItem(tmp, new FullPlateArmour);
        }else if(cmd1=="Door"){
                ss>>param1>>param2>>cmd2>>param3>>param4;
                ss.clear();
                Position P,A;                   
                P.heigth=param1;
                P.width=param2;
                A.heigth=param3;
                A.width=param4;
                
                if(cmd2=="Switch"){
                    m_map.placePassive_Active(P,A,new Door,new Switch);
                }else{
                    m_map.placePassive_Active(P,A,new Door,new Lever);
                }
        }else if(cmd1=="Trap"){
                ss>>param1>>param2;
                ss.clear();
                Position tmp;
                tmp.heigth=param1;
                tmp.width=param2;
                m_map.placeSpecialTile(tmp,new Trap);
        }
   
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
        
        if (dir==0){
            Menue(m_Chars[i]);
        }else{
        
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
         m_counter++;
       Tile* after=m_map.findTile(tmp); //Speichern des Tiles nach dem Zug
       before->onLeave(after);
    }
    }
}

void GameEngine::run(){
    while(!finished()){
        m_Chars[0]->showInfo();
        m_map.print(m_map.findCharacter(m_Chars[0]));
        turn();
    }
}

void GameEngine::printMenue()
{
    std::cout << "1. Spielerinfos " << std::endl;
    std::cout << "2. Zurück" << std::endl;
    std::cout << "3. Beenden." << std::endl;
}

void GameEngine::Menue(Character* c)
{
    bool end = false;
    while (!end)
    {
        printMenue();
        int input;
        std::cout << "Was möchten Sie tun?";
        std::cin >> input;
        switch (input)
        {
        case 1: c->showInfo();
            break;
        case 2: end = true;
            break;
        case 3: m_counter = 31; end = true;
            break;

        }
    }
}