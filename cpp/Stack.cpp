#include "D:\Downloads\Battle-Ship-main\header\Stack.h"

Stack::Stack()
{
    this->BotHunt=new Node[36];
    this->current=-1;
}

void Stack::Push(Node Node)
{
    this->current++;
    if(this->current<36)
    {
        if(Node.GetHit() != 1 || Node.GetHit() != 0)
            this->BotHunt[this->current]=Node;
    }
    else 
    {
        cout<<"Stack full "<<endl;
        return;
    }
}
Node Stack::Pop()
{
    int check= this->current;
    if(check<0) 
    {
        cout<<"Stack empty "<<endl;
        this->BotHunt=nullptr;
        return Node(-1);
    }
    else{
        this->current--;
        return this->BotHunt[check];
    }
}
Stack::~Stack()
{
    delete[] BotHunt;
}
bool Stack::ChechNull(){
    return (this->current>-1);
}
void Stack::DisplayStack()
{
    int x=this->current;
    for(int i=x;i>=0;i--)
    {
        cout<<this->BotHunt[i].GetX()<<" , " <<this->BotHunt[i].GetY()<<endl;
    }
}