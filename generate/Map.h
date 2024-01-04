#include "Node.h"
#include <iostream>
using namespace std;
class Map
{
    public:
        Node** m;
        static int mapSize;
    public:
        Map();
        Map(const int=1,const int=1);
        ~Map();
        Map& operator()(const int,const int);
        Node* GetNode(const int ,const int );
        bool ValidShipPlacement(Node&,const int& length,const int& angle);
        void DisplayIsPlace();
};