#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class LinkedList {
private:
    node* head;

public:
    LinkedList();
    bool isLoop();
    ~LinkedList();
    void clear();
};

// Constructor to create a linked list with a loop for testing
LinkedList::LinkedList() {
    node* p = new node;
    node* q = new node;
    node* r = new node;
    node* s = new node;

    // Initializing head and other nodes
    head = new node;
    head->data = 2;
    head->next = p;
    p->data = 5;
    p->next = q;
    q->data = 6;
    q->next = r;
    r->data = 7;
    r->next = s;
    s->data = 11;
    s->next = r; // Creating a loop (last node points back to node r)
}

// Function to check if there is a loop in the linked list
bool LinkedList::isLoop() {
    node* p = head; // Slow pointer
    node* q = head; // Fast pointer

    // Using Floyd’s Cycle-Finding Algorithm (Tortoise and Hare Algorithm)
    while (q != NULL && q->next != NULL) {
        p = p->next;       // Move slow pointer one step
        q = q->next->next; // Move fast pointer two steps

        if (p == q) { // If they meet, there's a loop
            return true;
        }
    }
    return false; // No loop found
}

// Destructor to clean up the linked list
LinkedList::~LinkedList() {
    clear(); // Call clear to delete all nodes
}

// Method to clear the linked list, safely breaking any loop if it exists
void LinkedList::clear() {
    // First, check if there is a loop
    if (isLoop()) {
        // Use two pointers to find the start of the loop
        node* slow = head;
        node* fast = head;

        // Move pointers until they meet
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Loop detected
                break;
            }
        }

        // If loop is detected, find the node before the loop starts
        if (slow == fast) {
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL; // Break the loop
        }
    }

    // Now safely delete all nodes
    node* current = head;
    while (current != NULL) {
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = NULL; // Set head to NULL to indicate list is empty
}

int main() {
    LinkedList list; // Create a LinkedList instance
    if (list.isLoop()) { // Check if the list contains a loop
        cout << "The linked list contains a loop." << endl;
    } else {
        cout << "The linked list does not contain a loop." << endl;
    }

    // Destructor is automatically called here, which clears the list

    return 0;
}
