#include "List.h"
#include <iostream>
using namespace std;
List:: List()
{
    length =0;
    start = NULL;
}

List:: ~List()
{
    Empty();
}

/* Desc: Allows us to check if we have space to add new items or not
 * Logic: Try creating a new node on the heap, if error => full else not
 * Complexity: O(1)
 */
bool List:: IsFull() const
{
    Node* temp;
    try 
    {
        temp = new Node;
        free(temp);
        return false;
    }
    catch(bad_alloc exec)
    {
        if(temp != NULL)
            free(temp);
        
        return true;
    }
}

/* Logic: we will insert at start, so that O(1) is maintained and no need
 * to traverse till end to insert
 * Complexity: O(1)
 */
void List::InsertItem(int item)
{
    if (!IsFull())
    {
        // hold the inserting item data in a temporary node
        Node* temp = new Node;
        temp->data = item;
        
        // We should point this temp to the node what start is pointing
        temp->next = start;
        
        // next move the start ie. make the start point to this temp
        start = temp;
        
        length++;
    }
    else
        cout <<"Can't insert heap is full";
}

/* Will empty the complete list */
void List::Empty()
{
    Node* temp;
    while(start != NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
        length --;
    }
}

/* Complexity: O(n)
 */
void List::Show() const
{
    // lets not send the start to the last and never reach back :P
    Node* jrStart = start;
    
    // lets move jrStart
    while(jrStart != NULL)
    {
        cout<< jrStart->data << endl;
        jrStart = jrStart->next;
    }
    
    //cleanup time
    delete jrStart;
}

int List::GetLength() const
{
    return length;   
}

void List::DeleteItem(int item)
{
    Node* temp = start;
    while(temp != NULL)
    {
        Node* target;
        
        // check current + 1
        if (temp->next != NULL && temp->next->data == item)
        {
            target = temp->next;
            temp->next = target->next;
            delete target;
            length--;
        }
        
        temp = temp->next;
        
    }
}