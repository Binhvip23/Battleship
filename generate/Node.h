class Node
{
    private:
        int row;
        int colum;
        int isplace;
    public:
        Node(int=1,int=1,int=0);
        ~Node();
        int& GetRow();
        int& GetColum();
        int& GetPlace();
};