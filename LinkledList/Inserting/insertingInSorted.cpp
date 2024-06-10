#include <iostream>
using namespace std;

class node
{
public:
    int data;   // Data part of the node
    node *next; // Pointer to the next node
};

class LinkedList
{
private:
    node *first; // Pointer to the first node in the linked list

public:
    LinkedList(); // Constructor to initialize the linked list
    void init();
    bool isSorted();            // Function to check if the linked list is sorted
    void insertinSorted(int x); // Function to insert a node in a sorted linked list
    void display();             // Function to display the linked list
    ~LinkedList();              // Destructor to clean up the linked list
};

// Constructor to initialize the linked list
LinkedList::LinkedList()
{
    first = NULL; // Initially, the list is empty
}

// Function to check if the linked list is sorted
bool LinkedList::isSorted()
{
    int x = INT32_MIN; // Initialize x with the smallest possible integer value
    node *p = first;   // Pointer to traverse the list
    while (p != NULL)
    {
        if (p->data < x)
        {
            return false; // If any node's data is less than the previous node's data, return false
        }
        x = p->data; // Update x to the current node's data
        p = p->next; // Move to the next node
    }
    return true; // If the loop completes without finding any disorder, return true
}

// Function to insert a node in a sorted linked list
void LinkedList::insertinSorted(int x)
{
    node *p = first; // Pointer to traverse the list
    node *q = NULL;  // Pointer to keep track of the previous node
    while (p && p->data < x)
    {
        q = p;       // Move q to the current node
        p = p->next; // Move p to the next node
    }
    node *t = new node; // Create a new node
    t->data = x;        // Set the data of the new node
    t->next = q->next;  // Link the new node to the next node
    q->next = t;        // Link the previous node to the new node
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

int main()
{
    LinkedList ll;
    ll.init();
    if (ll.isSorted())
    {
        ll.insertinSorted(21);
        ll.display();
    }
    else
    {
        cout<<"Not sorted"<<endl;
    }
}
