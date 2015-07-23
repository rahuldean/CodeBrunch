#include "Node.h"

class List
{
    public:
        List();
        ~List();
        bool IsFull() const;
        void InsertItem(int item);
        void DeleteItem(int item);
        void Show() const;
        void Empty();
        int GetLength() const;
    private:
        int length;
        Node* start;
};