#include <iostream>
using namespace std;

// Define the node class representing each element of the linked list
class node
{
public:
    int data;    // Data stored in the node
    node *next;  // Pointer to the next node
};

// Define the LinkedList class for linked list operations
class LinkedList
{
private:
    node *first = NULL;  // Pointer to the first node of the list

    // Private helper functions for different recursive length calculations
    int length_rec_m1(node *p);
    int length_rec_m2(node *p);
    int length_rec_m3(node *p);
    int length_rec_m4(node *p);

public:
    LinkedList();        // Constructor to initialize the linked list
    void init();         // Function to initialize the linked list with user input
    void display();      // Function to display the elements of the linked list
    int length();        // Function to calculate the length of the list (non-recursive)
    int length_rec_m1(); // Wrapper function for length_rec_m1
    int length_rec_m2(); // Wrapper function for length_rec_m2
    int length_rec_m3(); // Wrapper function for length_rec_m3
    int length_rec_m4(); // Wrapper function for length_rec_m4
    ~LinkedList();       // Destructor to clean up the linked list
};

// Constructor to initialize the linked list with a dummy node
LinkedList::LinkedList()
{
    first = new node;
    first->data = 0;
    first->next = NULL;
}

// Function to initialize the linked list with user input
void LinkedList::init()
{
    int n;   // Variable to store the number of elements
    cout << "Enter total no. of elements: ";
    cin >> n;
    node *t, *last = NULL;  // Temporary node pointer and last pointer for traversal
    if (n > 0)
    {
        for (int i = 0; i < n; i++)   // Loop to create n nodes
        {
            t = new node;  // Create a new node
            cout << "Enter Element " << i + 1 << ": ";
            cin >> t->data;  // Input data for the node
            t->next = NULL;  // Set next of new node to NULL
            if (i == 0)      // If it is the first node
            {
                first = t;   // Set first to the new node
                last = t;    // Set last to the new node
            }
            else
            {
                last->next = t;  // Link the last node to the new node
                last = t;        // Update last to the new node
            }
        }
    }
}

// Function to display the elements of the linked list
void LinkedList::display()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->data << " "; // Printing data of the current node
        p = p->next;            // Moving to the next node
    }
    cout << endl;
}

// Function to calculate the length of the list (non-recursive)
int LinkedList::length()
{
    int count = 0;
    node *p = first;
    while (p != NULL)
    {
        count++;    // Increment the count for each node
        p = p->next; // Move to the next node
    }
    return count;    // Return the count as the length of the list
}

// Private helper function for recursive length calculation (method 1)
int LinkedList::length_rec_m1(node *p)
{
    if (p == NULL)
    {
        return 0;    // Base case: if the node is NULL, return 0
    }
    else
    {
        return length_rec_m1(p->next) + 1;    // Recursive call and add 1
    }
}

// Private helper function for recursive length calculation (method 2)
int LinkedList::length_rec_m2(node *p)
{
    if (p == NULL)
    {
        return 0;    // Base case: if the node is NULL, return 0
    }
    else
    {
        return 1 + length_rec_m2(p->next);    // Add 1 and recursive call
    }
}

// Private helper function for recursive length calculation (method 3)
int LinkedList::length_rec_m3(node *p)
{
    if (p != NULL)
    {
        return 1 + length_rec_m3(p->next);    // Add 1 and recursive call
    }
    else
    {
        return 0;    // Base case: if the node is NULL, return 0
    }
}

// Private helper function for recursive length calculation (method 4)
int LinkedList::length_rec_m4(node *p)
{
    int x = 0;
    if (p != NULL)
    {
        x = length_rec_m4(p->next);    // Recursive call
        return x + 1;    // Add 1 to the result of the recursive call
    }
    else
    {
        return 0;    // Base case: if the node is NULL, return 0
    }
}

// Wrapper function for length_rec_m1
int LinkedList::length_rec_m1()
{
    return length_rec_m1(first);
}

// Wrapper function for length_rec_m2
int LinkedList::length_rec_m2()
{
    return length_rec_m2(first);
}

// Wrapper function for length_rec_m3
int LinkedList::length_rec_m3()
{
    return length_rec_m3(first);
}

// Wrapper function for length_rec_m4
int LinkedList::length_rec_m4()
{
    return length_rec_m4(first);
}

// Destructor to clean up the linked list
LinkedList::~LinkedList()
{
    node *p = first;
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
    LinkedList ll;    // Create a LinkedList object
    ll.init();    // Initialize the linked list with user input
    ll.display();    // Display the elements of the linked list
    cout << "Length of the linked list is " << ll.length() << endl;    // Print the length (non-recursive)
    cout << "Length of the linked list (rec_m1) is " << ll.length_rec_m1() << endl;    // Print the length (rec_m1)
    cout << "Length of the linked list (rec_m2) is " << ll.length_rec_m2() << endl;    // Print the length (rec_m2)
    cout << "Length of the linked list (rec_m3) is " << ll.length_rec_m3() << endl;    // Print the length (rec_m3)
    cout << "Length of the linked list (rec_m4) is " << ll.length_rec_m4() << endl;    // Print the length (rec_m4)
    return 0;    // Return 0 to indicate successful execution
}
