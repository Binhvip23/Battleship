#include "Node.h"

class Stack
{
    protected:
        Node* BotHunt;
        int current;
        int size;
    public:
        Stack();
        ~Stack();
        void Push(Node&);
        Node* Pop();
        bool ChechNull();
        void MakeNull();
        void DisplayStack();
        bool CheckforDup(const Node&);
};