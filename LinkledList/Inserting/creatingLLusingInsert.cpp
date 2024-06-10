#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class LinkedList
{
private:
    node *first, *last;

public:
    LinkedList();
    void insert(int x);
    void display();
    ~LinkedList();
};
LinkedList::LinkedList()
{
    first = NULL;
    last = first;
}
void LinkedList::insert(int x)
{
    node *t = new node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
// Function to display the linked list
void LinkedList::display()
{
    node *p = first;
    while (p != NULL)
    {                           // Traverse through the list
        cout << p->data << " "; // Print data of the current node
        p = p->next;            // Move to the next node
    }
    cout << endl;
}

// Destructor to clean up the linked list
LinkedList::~LinkedList()
{
    node *p = first; // Pointer to traverse the list
    while (first)
    {                        // Traverse through the list
        first = first->next; // Move to the next node
        delete p;            // Delete the current node
        p = first;           // Update p to the next node
    }
}
int main(){
    LinkedList ll;
    ll.insert(12);
    ll.insert(32);
    ll.insert(4);
    ll.insert(43);
    ll.insert(34);
    ll.display();
    return 0;
}