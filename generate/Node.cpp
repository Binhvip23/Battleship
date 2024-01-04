#include"Node.h"

Node::Node(int xVal,int yVal,int place):isplace(0),row(yVal),colum(xVal)
{}
Node::~Node()
{}

int& Node::GetRow()
{
    return this->row;
}
int& Node::GetColum()
{
    return this->colum;
}
int& Node::GetPlace()
{
    return this->isplace;
}