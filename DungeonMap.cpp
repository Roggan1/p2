/* 
 * File:   DungeonMap.cpp
 * Author: fs
 * 
 * Created on 9. Mai 2017, 14:42
 */

#include <map>
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

    m_data[P.heigth][P.width] = pass;
    m_data[A.heigth][A.width] = act;

    dynamic_cast<Active*> (m_data [A.heigth][A.width])->setP_Objekt(dynamic_cast<Passive*> (m_data[P.heigth][P.width]));

}

void DungeonMap::placeSpecialTile(Position pos, Tile* Special)
{
    delete m_data[pos.heigth][pos.width];
    m_data[pos.heigth][pos.width] = Special;
}

void DungeonMap::placeItem(Position pos, Item* ItemG)
{
    dynamic_cast<Floor*> (m_data[pos.heigth][pos.width])->placeItem(ItemG);
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
            if (m_data[i][j]->hasCharacter() && hasLineOfSight(from, findTile(m_data[i][j])))
            {
                cout << m_data[i][j]->getChar()->getFigur() << " ";
            }
            else if (hasLineOfSight(from, findTile(m_data[i][j])))
            {
                cout << m_data[i][j]->getSymbol() << " ";
            }
            else
            {
                cout << "# ";
            }
        }
    }

}

bool DungeonMap::hasLineOfSight(Position from, Position to)
{
    //http://www.k-achilles.de/algorithmen/bresenham-gerade.pdf
    int x = from.heigth;
    int y = from.width;

    int dx = to.heigth - from.heigth;
    int dy = to.width - from.width;
    int xstep = 1;
    int ystep = 1;

    if (dx < 0)
    {
        dx = -dx;
        xstep = -1;
    }

    if (dy < 0)
    {
        dy = -dy;
        ystep = -1;
    }
    int a = 2 * dx;
    int b = 2 * dy;

    if (dy <= dx)
    {
        int f = -dx;
        while (x != to.heigth)
        {
            if (m_data[x][y]->isTransparent() == false)
            {
                return false;
            }
            f = f + b;
            if (f > 0)
            {
                y = y + ystep;
                f = f - a;
            }
            x = x + xstep;
        }
    }
    else
    {
        int f = -dy;
        while (y != to.width)
        {
            if (m_data[x][y]->isTransparent() == false)
            {
                return false;
            }
            f = f + a;
            if (f > 0)
            {
                x = x + xstep;
                f = f - b;
            }
            y = y + ystep;
        }
    }

    return true;

}
//Überladungen für STL Container
bool operator<(Position left, Position right)
{
    if (left.heigth <= right.heigth) {
        if (left.heigth < right.heigth)
            return true;
        else if (left.width < right.width)
            return true;
    }
    return false;
}

bool operator<=(Position left, Position right)
{
    if (left.heigth <= right.heigth && left.width <= right.width)
        return true;
    return false;
}

bool operator<(Kante left, Kante right)
{
    if (left.a <= right.a && left.b <= right.b)
    {
        return false;
    }
    return true;
}

bool Position::operator==(Position right) const
{
    if (heigth == right.heigth && width == right.width)
        return true;
    return false;
}

Position& Position::operator=(Position right)
{
    heigth = right.heigth;
    width = right.width;
    return *this;
}

int DungeonMap::getPathTo(Position from, Position to)       //https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
{    
    set<Position> Q;
    map<Position,int> dist;
    map<Position,Position> prev;
    set<Position> neighbours;
    set<Kante> kanten;
    list<Position> sequence;
    
    for(int i = 0; i < m_width; i++)        //Q mit Knoten füllen
    {
        for(int j = 0; j < m_height; j++)
        {
            if (m_data[i][j]->isTransparent())
            {      
                Position p{i,j};
                Q.insert(p);
            }
        }
    }
   //Knoten mit Kanten Verbinden 
    set<Position>::iterator first_pos_it;
    set<Position>::iterator second_pos_it;
    for (first_pos_it = Q.begin(); first_pos_it != Q.end(); ++first_pos_it) {
        for (second_pos_it = Q.begin(); second_pos_it != Q.end(); ++second_pos_it) {
            if ((abs(first_pos_it->heigth - second_pos_it ->heigth) == 0 && abs(first_pos_it->width - second_pos_it->width) == 1) 
                    || (abs(first_pos_it->heigth - second_pos_it ->heigth) == 1 && abs(first_pos_it->width - second_pos_it->width) == 0) 
                    || (abs(first_pos_it->heigth - second_pos_it ->heigth) == 1 && abs(first_pos_it->width - second_pos_it->width) == 1)) {
                kanten.insert(Kante(Position(first_pos_it->heigth, first_pos_it->width), Position(second_pos_it->heigth, second_pos_it->width)));
            }
        }
    }
    
     for (auto& v : Q)    //Initialisierung
     {
        dist[v] = 15384;            //Default Distance
        prev[v] = Position(0, 0);   //Default Previous Position

    }
    
    dist[from] = 0;                 //Distance von Anfang zu Anfang
    
    while(!Q.empty())       //Knoten mit der kleinsten Distance wird benutzt
    {
        Position u = getMinDist(Q, dist);   //kleinste Distance wird an u gesetzt
        Q.erase(u);                 //Benutzter Knoten wird aus Q gelöscht
        
        neighbours.clear();         //neue Nachbarn werden gesetzt
        neighbours = getNeighbours(u, kanten);  //erzeugen der Nachbar Knoten
        
        int alt;                    

        for (auto& v : neighbours) {    //Schaut es alle Nachbarn an
            alt = dist[u] + 1;
            if (alt < dist[v]) {        //vergleicht mit dem bisheringen kürzesten Weg
                dist[v] = alt;          //-> wird geupdatet
                prev[v] = u;
            }
        }
    }
    Position u = to;
    while (!(prev[u] == Position(0, 0))) {      //alle Knoten die nicht den default Wert haben werden in die Sequenz geladen
        sequence.insert(sequence.begin(), u);
        u = prev[u];
    }
    
    if (sequence.empty())
        cout << "Es konnte kein Weg gefunden werden!" << endl;
    
    to = *(sequence.begin());           //Move zu Position in int Wert übersetzen
    
        if (to == from) {
        return 5;
    } else if ((to.heigth - from.heigth) == 0) {
        if ((to.width - from.width) <= -1)
            return 4;
        else if ((to.width - from.width >= 1))
            return 6;
    } else if ((to.width - from.width) == 0) {
        if ((to.heigth - from.heigth) <= -1)
            return 8;
        else if ((to.heigth - from.heigth) >= 1)
            return 2;
    } else if ((to.heigth - from.heigth) <= -1) {
        if ((to.width - from.width) <= -1)
            return 7;
        else if ((to.width - from.width) >= 1)
            return 9;
    } else if ((to.heigth - from.heigth) >= 1) {
        if ((to.width - from.width) <= -1)
            return 1;
        else if ((to.width - from.width) >= 1)
            return 3;
    }
    
    return 5;
}       


Position DungeonMap::getMinDist(set<Position>& Q, map<Position, int>& dist) const
{
    int min = numeric_limits<int>::max();   //Mindestwert zum Vergleich
    Position return_pos(0, 0);              
    for (auto& pos : Q) {
        if (dist[pos] <= min) {             //Distancen werden Verglichen
            min = dist[pos];
            return_pos = pos;
        }
    }
    return return_pos;
}

set<Position> DungeonMap::getNeighbours(Position pos,const set<Kante>& kanten) const 
{
    set<Position> return_set;           
    for (auto& kante : kanten) {            
        if (kante.a == pos) {               //Schaut wenn es der erste Nachbar die Position ist wird der zweite Nachbar hinzugefügt
            return_set.insert(kante.b);
        } else if (kante.b == pos) {        //Schaut wenn der zweite Nachbar die Position ist wird der erste Nachbar hinzugefügt
            return_set.insert(kante.a);
        }
    }
    return return_set;
}


//Konstruktoren
Position::Position()
{
    
}

Position::Position(int heigth1, int width1)
{
    heigth = heigth1;
    width = width1;
}

Kante::Kante(Position pos1, Position pos2)
{
    if (pos1 < pos2) {
        a = pos1;
        b = pos2;
    } else {
        a = pos2;
        b = pos1;
    }
}