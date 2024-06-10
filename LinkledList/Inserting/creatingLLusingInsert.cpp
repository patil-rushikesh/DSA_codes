#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class node {
public:
    int data;   // Data stored in the node
    node *next; // Pointer to the next node
};

// LinkedList class for linked list operations
class LinkedList {
private:
    node *first; // Pointer to store the first node of the Linked List

public:
    LinkedList();       // Constructor to initialize the linked list
    void init();        // Function to add elements to the linked list
    void insert(int, int); // Function to insert an element at a given position
    void display();     // Function to display the linked list
    ~LinkedList();      // Destructor to deallocate the memory of the nodes
};

// Constructor to initialize the first pointer to NULL
LinkedList::LinkedList() {
    first = NULL;
}

// Function to initialize the linked list with user input
void LinkedList::init() {
    int n; // Variable to store the number of elements
    cout << "Enter total no. of elements: ";
    cin >> n;
    node *t, *last = NULL; // Temporary node pointer and last pointer for traversal

    if (n > 0) {
        for (int i = 0; i < n; i++) { // Loop to create n nodes
            t = new node; // Create a new node
            cout << "Enter Element " << i + 1 << ": ";
            cin >> t->data; // Input data for the node
            t->next = NULL; // Set next of new node to NULL

            if (i == 0) { // If it is the first node
                first = t; // Set first to the new node
                last = t;  // Set last to the new node
            } else {
                last->next = t; // Link the last node to the new node
                last = t;       // Update last to the new node
            }
        }
    }
}

// Function to insert an element at a given position
void LinkedList::insert(int pos, int x) {
    node *t, *p;
    if (pos == 0) { // If the position is 0, insert at the beginning
        t = new node; // Create a new node
        t->data = x;  // Set the data for the new node
        t->next = first; // Link the new node to the first node
        first = t; // Update the first pointer to the new node
    } else if (pos > 0) { // If the position is greater than 0
        p = first;
        for (int i = 0; i < pos - 1; i++) { // Traverse to the node before the position
            p = p->next;
        }
        if (p) { // If the node exists
            t = new node; // Create a new node
            t->data = x;  // Set the data for the new node
            t->next = p->next; // Link the new node to the next node
            p->next = t; // Link the previous node to the new node
        }
    }
}

// Function to display the linked list
void LinkedList::display() {
    node *p = first;
    while (p != NULL) { // Traverse through the list
        cout << p->data << " "; // Print data of the current node
        p = p->next;            // Move to the next node
    }
    cout << endl;
}

// Destructor to clean up the linked list
LinkedList::~LinkedList() {
    node *p = first; // Pointer to traverse the list
    while (first) { // Traverse through the list
        first = first->next; // Move to the next node
        delete p; // Delete the current node
        p = first; // Update p to the next node
    }
}

// Main function to demonstrate linked list operations
int main() {
    LinkedList ll; // Create a LinkedList object
    ll.init(); // Initialize the linked list
    int x, pos, ch = 1; // Variables for element value, position, and choice
    while (ch != 0) { // Loop until user chooses to stop
        cout << "Enter Position : ";
        cin >> pos;
        cout << "Enter Element : ";
        cin >> x;
        ll.insert(pos, x); // Insert element at the given position
        ll.display(); // Display the linked list after insertion
        cout << "To continue press 1 else 0: ";
        cin >> ch;
    }
}
