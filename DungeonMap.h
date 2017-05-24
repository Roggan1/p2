/* 
 * File:   DungeonMap.h
 * Author: fs
 *
 * Created on 9. Mai 2017, 14:42
 */

#ifndef DUNGEONMAP_H
#define	DUNGEONMAP_H
#include "Tile.h"
#include <vector>
#include "Wall.h"
#include "Floor.h"
#include "Door.h"
#include "Switch.h"

struct Position {
        int heigth;
        int width;
    };
    
class DungeonMap {
public:
    
    DungeonMap(const int height, const int width);
    DungeonMap(const int height, const int width, const vector<string>& data);
    virtual ~DungeonMap();
    
    void place(Position pos, Character* c);
    void placeDoor_Switch(Position pos_D, Position pos_S);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print();
    
private:
    Tile*** m_data;
    int m_height;
    int m_width;
};

#endif	/* DUNGEONMAP_H */

