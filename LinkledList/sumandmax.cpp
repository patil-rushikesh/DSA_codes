#include<iostream>
using namespace std;

// Define the node class representing each element of the linked list
class node{
    public:
        int data;     // Data stored in the node
        node *next;   // Pointer to the next node
};

// Define the LinkedList class for linked list operations
class LinkedList{
    private:
        node *first, *last;   // Pointers to the first and last nodes of the list
        // Private helper functions for recursive sum and max operations
        int sum_rec(node *p);  
        int max_rec(node *p);
    public:
        LinkedList();         // Constructor to initialize the linked list
        void init();          // Function to initialize the linked list with user input
        int sum();            // Function to calculate the sum of elements (non-recursive)
        int sum_rec();        // Function to calculate the sum of elements (recursive)
        int max();            // Function to find the maximum element (non-recursive)
        int max_rec();        // Function to find the maximum element (recursive)
        ~LinkedList();        // Destructor to clean up the linked list
};

// Constructor to initialize the linked list
LinkedList::LinkedList(){
    first = NULL;    // Initialize first to NULL
    last = first;    // Initialize last to the same value as first
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

// Function to calculate the sum of elements (non-recursive)
int LinkedList::sum(){
    int sum=0;    // Initialize sum to 0
    node *p = first;   // Pointer to traverse the list
    while(p != NULL){
        sum = sum + p->data;  // Add data of current node to sum
        p = p->next;          // Move to the next node
    }
    return sum;    // Return the calculated sum
}

// Function to calculate the sum of elements (recursive)
int LinkedList::sum_rec(){
    return sum_rec(first);    // Call the private recursive function
}

// Private helper function for recursive sum
int LinkedList::sum_rec(node *p){
    if(p == 0){
        return 0;    // Base case: if the node is NULL, return 0
    }else{
        return sum_rec(p->next) + p -> data;    // Recursive call and add current node's data
    }
}

// Function to find the maximum element (non-recursive)
int LinkedList::max(){
    int max = INT32_MIN;    // Initialize max to the smallest integer value
    node *p =first;         // Pointer to traverse the list
    while(p){
        if(p->data > max){
            max = p ->data;  // Update max if current node's data is larger
        }
        p = p -> next;       // Move to the next node
    }
    return max;    // Return the maximum value found
}

// Function to find the maximum element (recursive)
int LinkedList::max_rec(){
    return max_rec(first);    // Call the private recursive function
}

// Private helper function for recursive max
int LinkedList::max_rec(node *p){
    int x = 0;
    if(p == 0){
        return INT32_MIN;    // Base case: if the node is NULL, return the smallest integer value
    }else{
        x = max_rec(p->next);  // Recursive call to find max in the rest of the list
        if(x > p -> data){
            return x;   // Return the larger value between current node's data and max from rest of the list
        }else{
            return p -> data;
        }
    }
}

// Destructor to clean up the linked list
LinkedList::~LinkedList()
{
    node *p = first;    // Pointer to traverse the list
    while (first)
    {
        first = first->next;    // Move to the next node
        delete p;               // Delete the current node
        p = first;              // Update p to the next node
    }
}

// Main function to demonstrate the linked list operations
int main()
{
    LinkedList ll;    // Create a LinkedList object
    ll.init();    // Initialize the linked list with user input
    cout << "Sum of the linked list is " << ll.sum() << endl;    // Print the sum (non-recursive)
    cout << "Sum of the linked list using recursive method is " << ll.sum_rec() << endl;    // Print the sum (recursive)
    cout << "Maximum element of the linked list is " << ll.max() << endl;    // Print the max (non-recursive)
    cout << "Maximum element of the linked list using recursive method is " << ll.max_rec() << endl;    // Print the max (recursive)
    return 0;    // Return 0 to indicate successful execution
}
