#include "Map.h"

int Map::mapSize=6;

Map::Map()
{
    this->m=new Node*[mapSize];
    for(int i=0;i<mapSize;i++)
    {
        *(this->m+i)=new Node[mapSize];
        for(int j=0;j<mapSize;j++)
        {
            this->m[i][j]=Node(j+1,i+1,0);
        }
    }
}
Map::Map(const int x0,const int y0)
{
    this->m = new Node*[Map::mapSize];
    for(int i = 0; i <Map::mapSize; i++)
    {
        *(this->m + i) = new Node[Map::mapSize];
        for(int j = 0; j <Map::mapSize; j++)
        {
            *(*(this->m + i) + j) = Node(j,i,0);
        }
    }
}
Map::~Map()
{ 
    for(int i = 0; i < Map::mapSize; i++)
    {
        delete[] *(this->m + i);
    }
    delete[] this->m;
}
Node* Map::GetNode(const int i, const int j)
{
    return (*(this->m + (j-1)) + (i-1));
}
bool Map::ValidShipPlacement(Node& n,const int& length,const int& angle)
{
    if(angle==0)
    {
        for(int i=0;i<length;i++)
            if(this->GetNode(n.GetColum()+i+1,n.GetRow()+1)->GetPlace()==1) return false;
        return true;
    }
    else
    {
        for(int i=0;i<length;i++)
            if(this->GetNode(n.GetColum()+1,n.GetRow()+i+1)->GetPlace()==1) return false;
        return true;
    }
}
void Map::DisplayIsPlace()
{
    cout<<endl;
    for(int i = 1; i <=mapSize; i++)
    {        
        cout << endl;
        for(int j = 1; j <=mapSize; j++)
        {
            int placeValue = this->GetNode(j, i)->GetPlace();
            if (placeValue == 0) {
                cout << "( - ) "; 
            } else if (placeValue == 1) {
                cout << "( B ) ";  
            }
        }
    }
}
Map& Map::operator()(const int x0, const int y0)
{
    for(int i = 0; i <Map::mapSize; i++)
    {
        for(int j = 0; j <Map::mapSize; j++)
        {
            *(*(this->m + i) + j) = Node(j,i);
        }
    }
    return (*this);
}