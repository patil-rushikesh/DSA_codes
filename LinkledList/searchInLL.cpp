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
    node *first;                        // Pointer to store the first node of the Linked List
    node *search_rec(node *p, int key); // Recursive function to perform linear search in linked list

public:
    LinkedList();                        // Constructor to initialize the linked list
    void init();                         // Function to add elements to the linked list
    node *search(int key);               // Function to perform linear search in linked list
    node *search_rec(int key);           // Function to perform linear search using recursion in linked list
    node *search_transposition(int key); // Function to search element and move it one step ahead to improve search next time
    node *search_moveToHead(int key);    // Function to search element and move it to head
    void display();                      // Function to display the linked list
    void displaySearchResult(node *p);   // Function to display search result
    ~LinkedList();                       // Destructor to deallocate the memory of the nodes
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

// Function to search an element using conventional method
node *LinkedList::search(int key) {
    node *p = first;
    while (p != NULL) { // Traverse through the list
        if (key == p->data) { // If key is found, return the node
            return p;
        }
        p = p->next; // Move to the next node
    }
    return NULL; // Return NULL if key is not found
}

// Support function to call recursive search function
node *LinkedList::search_rec(int key) {
    return search_rec(first, key); // Start recursive search from the first node
}

// Function to search an element using recursive method
node *LinkedList::search_rec(node *p, int key) {
    if (p == NULL) { // Base case: if the end of the list is reached
        return NULL;
    }
    if (key == p->data) { // If key is found, return the node
        return p;
    }
    return search_rec(p->next, key); // Recursive call to continue searching in the next node
}

// Function to search an element and move the searched element to head
node *LinkedList::search_moveToHead(int key) {
    node *p = first;
    node *q = NULL;
    while (p != NULL) { // Traverse through the list
        if (p->data == key) { // If key is found
            if (q != NULL) { // If it's not the first node
                q->next = p->next; // Remove node from its current position
                p->next = first; // Move it to the head
                first = p; // Update first to the moved node
            }
            return first; // Return the moved node
        }
        q = p; // Move q to the current node
        p = p->next; // Move p to the next node
    }
    return NULL; // Return NULL if key is not found
}

// Function to search an element and move it one step ahead
node *LinkedList::search_transposition(int key) {
    node *p = first;
    node *q = NULL;

    if (p == NULL) { // Handle empty list
        return NULL;
    }

    while (p != NULL) { // Traverse through the list
        if (p->data == key) { // If key is found
            if (q != NULL) { // If it's not the first node
                // Swap data of q and p
                int temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
            return p; // Return the node where key was found
        }
        q = p; // Move q to the current node
        p = p->next; // Move p to the next node
    }
    return NULL; // Return NULL if key is not found
}

// Function to display the linked list
void LinkedList::display() {
    node *p = first;
    while (p != NULL) { // Traverse through the list
        cout << p->data << " "; // Print data of current node
        p = p->next; // Move to the next node
    }
    cout << endl;
}

// Function to display the search result
void LinkedList::displaySearchResult(node *p) {
    if (p != NULL) { // If node is found
        cout << "Element Found: " << p->data << endl;
    } else { // If node is not found
        cout << "Element Not Found" << endl;
    }
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

int main() {
    LinkedList ll; // Create a LinkedList object
    ll.init(); // Initialize the linked list
    ll.display(); // Display the linked list

    int x = 0;
    cout << "Enter the key to search: ";
    cin >> x;

    // Perform search operations and display results
    ll.displaySearchResult(ll.search(x));
    ll.displaySearchResult(ll.search_rec(x));

    // Perform search and move-to-head operation
    node *p = ll.search_moveToHead(x);
    ll.display(); // Display the linked list after move-to-head operation
    ll.displaySearchResult(p);

    // Perform search and transposition operation
    node *p = ll.search_transposition(x);
    ll.display(); // Display the linked list after transposition operation
    ll.displaySearchResult(p);

    return 0;
}
