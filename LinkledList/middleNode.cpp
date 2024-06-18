#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

// Define the node class representing each element of the linked list
class node
{
public:
    int data;   // Data stored in the node
    node *next; // Pointer to the next node
};

// Define the LinkedList class for linked list operations
class LinkedList
{
private:
    node *first, *last; // Pointers to the first and last nodes of the list
public:
    LinkedList(); // Constructor to initialize the linked list
    void init();  // Function to initialize the linked list with user input
    int middleNode();
    int middleNode_stack();
    void display();
    ~LinkedList(); // Destructor to clean up the linked list
};

// Constructor to initialize the linked list
LinkedList::LinkedList()
{
    first = NULL; // Initialize first to NULL
    last = first; // Initialize last to the same value as first
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
        for (int i = 0; i < n; i++) // Loop to create n nodes
        {
            t = new node; // Create a new node
            cout << "Enter Element " << i + 1 << ": ";
            cin >> t->data; // Input data for the node
            t->next = NULL; // Set next of new node to NULL
            if (i == 0)     // If it is the first node
            {
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
int LinkedList::middleNode()
{
    node *p = first;
    node *q = first;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (q)
        {
            p = p->next;
        }
    }
    return p->data;
}

int LinkedList::middleNode_stack()
{
    stack<node *> s;
    node *p = first;
    while (p)
    {
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int popLength = (int)(floor(length / 2.0));
    while (popLength)
    {
        s.pop();
        popLength--;
    }

    return s.top()->data;
}

void LinkedList::display()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Destructor to clean up the linked list
LinkedList::~LinkedList()
{
    node *p = first; // Pointer to traverse the list
    while (first)
    {
        first = first->next; // Move to the next node
        delete p;            // Delete the current node
        p = first;           // Update p to the next node
    }
}

// Main function to demonstrate the linked list operations
int main()
{
    LinkedList ll; // Create a LinkedList object
    ll.init();     // Initialize the linked list with user input
    ll.display();
    cout << ll.middleNode();
    return 0; // Return 0 to indicate successful execution
}
