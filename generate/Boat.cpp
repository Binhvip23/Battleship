#include "Boat.h"
int Boat::boatNums = 3;
int Boat::ListOfBoatSize[5] = {2, 3, 3, 4,5};

Boat::Boat(const int x0,const int y0)
{
    this->p=new Node[this->boatNums];
    for(int i=0;i<this->boatNums;i++)
    {
        this->boatsize=this->ListOfBoatSize[i];
        *(this->p+i)= Node(x0,y0);
    }
}
Boat::~Boat()
{
    delete[] this->p;
}
Node* Boat::GetBoat(const int i)
{
    return &this->p[i];
}
Boat& Boat::operator()(const int x0, const int y0)
{
    for(int i = 0; i < Boat::boatNums; i++)
    {
        this->boatsize = Boat::ListOfBoatSize[i];
       *(this->p + i) = Node(x0,y0); 
    }
    return (*this);
}