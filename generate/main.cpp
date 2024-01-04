#include "memo.h"
#include "Boat.h"
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

int InitBoatAng(int i)
{
    srand(time(NULL) * (getpid() + i));
    int angle = rand() % 91 * 2;
    if(angle >= 90)
        angle = 90;
    else
        angle = 0;
    return angle;
}
Node InitNodePos(int i, Map& m,Map& generate,int seed)
{
    srand(time(NULL) *(getpid() + i+seed));
    int x = 0, y = 0, angle = InitBoatAng(i),
        temp = 7 - Boat::ListOfBoatSize[i];
    if(angle == 0)
    {
        x =1+ rand() % temp;
        y =1+ rand() % 6 ;
        if(m.ValidShipPlacement((*m.GetNode(x,y)),Boat::ListOfBoatSize[i],angle) && generate.ValidShipPlacement((*m.GetNode(x,y)),Boat::ListOfBoatSize[i],angle))
        {
            for(int j = 0; j < Boat::ListOfBoatSize[i]; j++)
            {
                m.GetNode(x + j, y)->GetPlace() += 1;
                generate.GetNode(x + j, y)->GetPlace() += 1;
            }                
        }
            else return Node(-1);
    }
    else
    {
        x =1+ rand() % 6;
        y =1+ rand() % temp;
        if(m.ValidShipPlacement((*m.GetNode(x,y)),Boat::ListOfBoatSize[i],angle) && generate.ValidShipPlacement((*m.GetNode(x,y)),Boat::ListOfBoatSize[i],angle))
        {
            for(int j = 0; j < Boat::ListOfBoatSize[i]; j++)
            {
                m.GetNode(x, y + j)->GetPlace() += 1;
                generate.GetNode(x, y + j)->GetPlace() += 1;
            }   
        }
        else return Node(-1);
    }
    return Node(x, y);
}
int main(int argc,char* argv[])
{
    int ValidConfigurationCounted=0,count =0;
    Boat bBot(1, 1);

    Map m1(1,1);
    Map generate(1,1);

    memo Botmemo;
    while(ValidConfigurationCounted<10000)
    {
        while(count < Boat::boatNums )
        {
            *bBot.GetBoat(count) = InitNodePos(count,m1,generate,1234);
            if(bBot.GetBoat(count)->GetColum() != -1)
            {
                count++;
            }
            if(count==3)
            {
                cout<<endl<<"Dummy Ship placement: "<<endl;
                m1.DisplayIsPlace();
            }
        }
        count = 0;
        for(int i=1;i<=6;i++)
            for(int j=1;j<=6;j++)
                *(Botmemo.GetNode(j,i))+=(generate.GetNode(j,i)->GetPlace());
        bBot(1,1);
        m1(1,1);
        generate(1,1);
        cout<<endl<<"Number of loops "<<++ValidConfigurationCounted<<endl;
        Botmemo.DisplayMemo();
        sleep_until(system_clock::now() + seconds(1));
    }
    return 0;
}