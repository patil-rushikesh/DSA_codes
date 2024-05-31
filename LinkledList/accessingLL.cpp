#include <iostream>
using namespace std;

// Creating a Node format
class Node
{
public:
    int data;        // stores data
    Node *next;      // stores pointer which points to next node
};

// Creating linked list
class LinkedList
{
private:
    Node *first;     // stores pointer which points to first node of the linked list

    void recursion_display(Node *p);            // helper method for recursive display
    void reverse_recursion_display(Node *p);    // helper method for reverse recursive display

public:
    LinkedList();                             // constructor
    void elements();                          // method to input elements into the linked list
    void display();                           // method to display linked list iteratively
    void recursion_display();                 // method to display linked list recursively
    void reverse_recursion_display();         // method to display linked list in reverse recursively
    ~LinkedList();                            // destructor
};

LinkedList::LinkedList()
{
    // Initializing first pointer to null
    first = NULL;
}

void LinkedList::elements()
{
    int n;
    cout << "Total No. to insert in Linked List: ";
    cin >> n;

    Node *last, *t;    // last pointer which will point to the last element of the linked list, t pointer which will point to the current element
    int value;

    if (n > 0)
    {
        cout << "Enter element 1: ";
        cin >> value;
        
        // Initializing first node and assigning the data and next pointer to null
        first = new Node;
        first->data = value;
        first->next = NULL;
        last = first;  // last pointer will point to the first node initially

        for (int i = 1; i < n; i++)
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            
            // Creating new node
            t = new Node;
            t->data = value;
            t->next = NULL;        // assigning new node's next pointer to null considering it as last node for now
            last->next = t;        // linking last node's next pointer to new node
            last = t;              // updating last pointer to point to the new last node
        }
    }
}

void LinkedList::display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";    // printing data of current node
        p = p->next;               // moving to next node
    }
    cout << endl;
}

void LinkedList::recursion_display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";     // printing data of current node
        recursion_display(p->next); // recursive call for next node
    }
}

void LinkedList::reverse_recursion_display(Node *p)
{
    if (p != NULL)
    {
        reverse_recursion_display(p->next); // recursive call for next node
        cout << p->data << " ";             // printing data after returning from recursive call
    }
}

void LinkedList::recursion_display()
{
    recursion_display(first);   // calling helper method for recursive display starting from first node
}

void LinkedList::reverse_recursion_display()
{
    reverse_recursion_display(first);  // calling helper method for reverse recursive display starting from first node
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;    // moving to next node
        delete p;               // deleting current node
        p = first;              // updating current node to next node
    }
}

int main()
{
    LinkedList ll;
    ll.elements();                    // inserting elements into the linked list
    cout << "Iterative Display: ";
    ll.display();                     // displaying elements iteratively
    cout << "Recursive Display: ";
    ll.recursion_display();           // displaying elements recursively
    cout << endl;
    cout << "Reverse Recursive Display: ";
    ll.reverse_recursion_display();   // displaying elements in reverse order recursively
    cout << endl;

    return 0;
}
