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
#include "Lever.h"
#include "Trap.h"
#include <set>
#include <list>
#include <limits>
#include <map>

struct Position {
        int heigth;
        int width;
        Position();
        Position (int heigth1, int width1);
        bool operator==(Position right) const;
        Position& operator=(Position right);
    };
    
    struct Kante {
        Position a;
        Position b;
        Kante(Position pos1, Position pos2);
    };
    
bool operator<(Kante left, Kante right);
bool operator<(Position left, Position right);

class DungeonMap {
public:
    
    DungeonMap(const int height, const int width);
    DungeonMap(const int height, const int width, const vector<string>& data);
    virtual ~DungeonMap();
    
    void place(Position pos, Character* c);
    void placePassive_Active(Position pos_P, Position pos_A,Passive* pass, Active* act);
    void placeSpecialTile(Position pos, Tile* Special);
    void placeItem(Position pos,Item* ItemG);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print(Position from);
    int getPathTo(Position from, Position to);
    Position getMinDist(set<Position>& Q, map<Position, int>& dist) const;
    set<Position> getNeighbours(Position pos, const set<Kante>& kanten) const;
    
    bool hasLineOfSight(Position from, Position to);
private:
    Tile*** m_data;
    int m_height;
    int m_width;
};

#endif	/* DUNGEONMAP_H */

