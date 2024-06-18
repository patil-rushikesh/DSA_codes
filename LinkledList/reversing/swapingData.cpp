
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
    void display();
    int length();
    void reverse();
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
void LinkedList::display()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->data << " "; // printing data of current node
        p = p->next;            // moving to next node
    }
    cout << endl;
}
void LinkedList::reverse()
{
    node *p = first;
    int *A = new int[length()];
    int i = 0;
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = A[i--];
        p = p->next;
    }
}
// Function to calculate the length of the list (non-recursive)
int LinkedList::length()
{
    int count = 0;
    node *p = first;
    while (p != NULL)
    {
        count++;     // Increment the count for each node
        p = p->next; // Move to the next node
    }
    return count; // Return the count as the length of the list
}

LinkedList::~LinkedList()
{
    node *p = first;
    while (p != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
int main()
{
    LinkedList ll;
    ll.init();
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}