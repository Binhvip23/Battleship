#include <iostream>
using namespace std;
class memo
{
    private:
        int** MapPlaceRecord;
        int row;
        int colum;
        static int BoardRecordSize;
    public:
        memo(int =8);
        memo(const memo&);
        ~memo();
        void DisplayMemo();
        int* GetNode(const int=1,const int =1);
};