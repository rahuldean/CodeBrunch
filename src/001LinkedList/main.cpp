#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    List list;
    list.InsertItem(2);
    list.InsertItem(1);
    list.InsertItem(10);
    
    cout << "Length" << list.GetLength() <<endl;
    list.Show();
    
    list.Empty();
    cout << "Length" << list.GetLength() <<endl;
    
    list.InsertItem(2);
    
    cout << "Length" << list.GetLength() <<endl;
    list.Show();
    
    
    list.InsertItem(2);
    list.InsertItem(3);
    list.InsertItem(12);
    list.InsertItem(23);
    list.InsertItem(52);
    list.InsertItem(72);
    list.InsertItem(21);
    list.InsertItem(21);
    
    cout << "Length" << list.GetLength() <<endl;
    list.Show();
    
    list.DeleteItem(21);
    cout << "Length" << list.GetLength() <<endl;
    list.Show();
    
    return 0;
}