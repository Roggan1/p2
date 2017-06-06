/* 
 * File:   DungeonMap.cpp
 * Author: fs
 * 
 * Created on 9. Mai 2017, 14:42
 */

#include "DungeonMap.h"

DungeonMap::DungeonMap(const int height, const int width)
{

    m_data = new Tile**[height];
    m_height = height;
    m_width = width;

    for (int i = 0; i < m_height; i++)
    {
        m_data[i] = new Tile*[width];
        for (int j = 0; j < m_width; j++)
        {
            m_data[i][j] = new Floor;
        }
    }
}

DungeonMap::DungeonMap(const int height, const int width, const vector<string>& data)
{
    m_data = new Tile**[height];
    m_height = height;
    m_width = width;

    for (int i = 0; i < m_height; i++)
    {
        m_data[i] = new Tile*[width];
        for (int j = 0; j < m_width; j++)
        {

            if (data[i].at(j) == '#')
            { //prüfen ob Wand oder Boden an Position ij  
                m_data[i][j] = new Wall;
            }
            else
            {
                m_data[i][j] = new Floor;
            }
        }
    }
}

DungeonMap::~DungeonMap()
{

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            delete m_data[i][j];
        }
        delete[] m_data[i];
    }
    delete[] m_data;

}

void DungeonMap::place(Position pos, Character* c)
{
    m_data[pos.heigth][pos.width]->setCharacter(c);
}

void DungeonMap::placePassive_Active(Position P, Position A, Passive* pass, Active* act)
{
    delete m_data[P.heigth][P.width];
    delete m_data[A.heigth][A.width];
    
    m_data[P.heigth][P.width]=pass;
    m_data[A.heigth][A.width]=act;
    
     dynamic_cast<Active*>(m_data [A.heigth][A.width])->setP_Objekt(dynamic_cast<Passive*>(m_data[P.heigth][P.width]));
    
}

void DungeonMap::placeSpecialTile(Position pos, Tile* Special)
{
    delete m_data[pos.heigth][pos.width];
    m_data[pos.heigth][pos.width]=Special;
}

void DungeonMap::placeItem(Position pos,Item* ItemG)
{
    dynamic_cast<Floor*>(m_data[pos.heigth][pos.width])->placeItem(ItemG);
}

Position DungeonMap::findTile(Tile* t)
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {

            if (m_data[i][j] == t)
            {
                Position tmp;
                tmp.heigth = i;
                tmp.width = j;
                return tmp;
            }

        }
    }
    
}

Tile* DungeonMap::findTile(Position pos)
{
    return m_data[pos.heigth][pos.width];
}

Position DungeonMap::findCharacter(Character* c)
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {

            if (m_data[i][j]->getChar() == c)
            {
                Position tmp;
                tmp.heigth = i;
                tmp.width = j;
                return tmp;
            }

        }
    }
    
}

void DungeonMap::print(Position from)
{
    for (int i = 0; i < m_height; i++)
    {
        cout << endl;
        for (int j = 0; j < m_width; j++)
        {
            if (m_data[i][j]->hasCharacter())
            {
                cout << m_data[i][j]->getChar()->getFigur()<<" ";
            }
            else if(hasLineOfSight(from,findTile(m_data[i][j]))){
                cout<<m_data[i][j]->getSymbol()<<" ";
            }
            else
            {
                cout<<"# ";
            }
        }
    }

}

bool DungeonMap::hasLineOfSight(Position from, Position to)
{
    int dx, dy;
    
    if (from.heigth>to.heigth){
     dx=from.heigth-to.heigth+1;
    }else{
         dx=to.heigth-from.heigth+1;
    }
    
    if (from.width>to.width){
     dy=from.width-to.width+1;
    }else{
        dy=to.width-from.width+1;
    }
    
    int x = to.heigth;
    int y = to.width;
    
    double error= 0.0;
    double s=dy/dx;
    
    while(x<=from.heigth){
        
        if(m_data[x][y]->isTransparent()){//überprüfung        
        x++;
        error+=s;
        if (error>0.5){
            y++;
            error--;
        }
        
    }else{
            return false;
    }
        return true;
}
}