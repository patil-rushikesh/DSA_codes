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
    node *first;

public:
    LinkedList();
    void init();
    int deleteNode(int pos);
    void display();
    ~LinkedList();
};

LinkedList::LinkedList()
{
    first = NULL;
}

// Function to initialize the linked list with user input
void LinkedList::init()
{
    int n; // Variable to store the number of elements
    cout << "Enter total no. of elements: ";
    cin >> n;
    node *t, *last = NULL; // Temporary node pointer and last pointer for traversal

    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {                 // Loop to create n nodes
            t = new node; // Create a new node
            cout << "Enter Element " << i + 1 << ": ";
            cin >> t->data; // Input data for the node
            t->next = NULL; // Set next of new node to NULL

            if (i == 0)
            {              // If it is the first node
                first = t; // Set first to the new node
                last = t;  // Set last to the new node
            }
            else
            {
                last->next = t; // Link the last node to the new node
                last = t;       // Update last to the new node
            }
        }
    }
}

int LinkedList::deleteNode(int pos)
{
    node *p, *q;
    int x, i;
    if (pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        delete p;
    }
    else
    {
        p = first;
        q = NULL;
        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
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
    ll.init();
    ll.display();
    ll.deleteNode(3);
    ll.display();
    return 0;
}