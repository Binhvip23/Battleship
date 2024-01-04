#include "memo.h"

int memo::BoardRecordSize=6;

memo::memo(int n)
{
    this->MapPlaceRecord =new int*[memo::BoardRecordSize+1];
    for(int i=1;i<=memo::BoardRecordSize;i++)
        {
            this->MapPlaceRecord[i]=new int[memo::BoardRecordSize+1];
            for(int j=1;j<=memo::BoardRecordSize;j++)
            {
                this->MapPlaceRecord[i][j]=0;
                this->row=i;
                this->colum=j;
            }
        }
}
memo::memo(const memo& m1)
{
    this->MapPlaceRecord =new int*[memo::BoardRecordSize+1];
    for(int i=1;i<=memo::BoardRecordSize;i++)
        {
            this->MapPlaceRecord[i]=new int[memo::BoardRecordSize+1];
            for(int j=1;j<=memo::BoardRecordSize;j++)
            {
                this->MapPlaceRecord[i][j]=m1.MapPlaceRecord[i][j];
                this->row=i;
                this->colum=j;
            }
        }
}
memo::~memo()
{
    for(int i=1;i<=BoardRecordSize;i++)
    {
        delete[] this->MapPlaceRecord[i];
    }
    delete [] *(this->MapPlaceRecord);
}
void memo::DisplayMemo()
{
    for(int i=1;i<=BoardRecordSize;i++)
        {
            cout<<endl;
            for(int j=1;j<=BoardRecordSize;j++)
                cout<<this->MapPlaceRecord[j][i]<<" ";
        }
    cout<<endl;
}
int* memo::GetNode(int i,int j)
{
    return (&this->MapPlaceRecord[i][j]);
}