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

void DungeonMap::placeDoor_Switch(Position D, Position S)
{
    delete m_data[D.heigth][D.width];
    delete m_data[S.heigth][S.width];
    
    m_data[D.heigth][D.width]=new Door;
    m_data[S.heigth][S.width]=new Switch;
    
    dynamic_cast<Switch*>(m_data [S.heigth][S.width])->setP_Objekt(dynamic_cast<Passive*>(m_data[D.heigth][D.width]));
    
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

void DungeonMap::print()
{
    for (int i = 0; i < m_height; i++)
    {
        cout << endl;
        for (int j = 0; j < m_width; j++)
        {
            if (m_data[i][j]->hasCharacter())
            {
                cout << "+ ";
            }
            else
            {
                cout<<m_data[i][j]->getSymbol()<<" ";
            }
        }
    }

}