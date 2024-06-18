#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class queue
{
private:
    node *front;
    node *rear;
    bool isEmpty();

public:
    queue();
    void enqueue(int x);
    int dequeue();
    void display();
    int queueFront();
    int queueRear();
    ~queue();
};

// Constructor to initialize the queue
queue::queue()
{
    front = nullptr; // Initialize front to nullptr
    rear = nullptr;  // Initialize rear to nullptr
}

// Method to check if the queue is empty
bool queue::isEmpty()
{
    return front == nullptr;
}

// Method to add an element to the queue
void queue::enqueue(int x)
{
    node *t = new node; // Allocate new node
    if (t == nullptr)
    {
        cout << "Heap Full" << endl;
        return;
    }
    t->data = x;
    t->next = nullptr;
    if (isEmpty())
    {
        front = rear = t; // If the queue is empty, both front and rear point to the new node
    }
    else
    {
        rear->next = t; // Link the new node at the end of the queue
        rear = t;       // Update rear to point to the new node
    }
}

// Method to remove an element from the queue
int queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Empty" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    else
    {
        node *p = front; // Temporarily store the front node
        int x = p->data; // Retrieve data from front node
        front = front->next; // Move front to the next node
        delete p; // Delete the old front node
        if (front == nullptr)
        {
            rear = nullptr; // If the queue is now empty, set rear to nullptr as well
        }
        return x;
    }
}

// Method to get the front element of the queue
int queue::queueFront()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    else
    {
        return front->data; // Return the front element's data
    }
}

// Method to get the rear element of the queue
int queue::queueRear()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    else
    {
        return rear->data; // Return the rear element's data
    }
}

// Method to display all elements in the queue
void queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue: ";
        node *p = front;
        while (p != nullptr) // Corrected the loop condition to display all elements
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

// Destructor to clean up the allocated memory
queue::~queue()
{
    node *p = front;
    while (front != nullptr)
    {
        front = front->next; // Move to next node
        delete p; // Delete current node
        p = front; // Update current node to next node
    }
}

int main()
{
    int x = 0;
    int choice;
    queue queue1;
    while (1)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. View from front\n4. View from Rear\n5. Display\n6. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element to add: ";
            cin >> x;
            queue1.enqueue(x);
            queue1.display();
            break;
        case 2:
            queue1.dequeue();
            queue1.display();
            break;
        case 3:
            cout << "Element on Front: " << queue1.queueFront() << endl;
            break;
        case 4:
            cout << "Element on Rear: " << queue1.queueRear() << endl;
            break;
        case 5:
            queue1.display();
            break;
        case 6:
            cout << "Exiting program!" << endl;
            return 0;
        default:
            cout << "Invalid Option Chosen!" << endl;
            break;
        }
    }
}
