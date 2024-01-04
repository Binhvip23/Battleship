#include"Map.h"
#include <time.h>
class Boat
{
    private:
        Node* p;
        int boatsize;
    public: 
        static int boatNums;
        static int ListOfBoatSize[5];
    public:
        Boat(const int =1,const int =1);
        ~Boat();
        Node* GetBoat(int);
        Boat& operator()(const int, const int);
};