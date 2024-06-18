#include <iostream>
using namespace std;

class queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
    bool isFull();
    bool isEmpty();

public:
    queue(int x);
    void enqueue(int x);
    int dequeue();
    void display();
    int queueFront();
    int queueRear();
    ~queue();
};

// Constructor to initialize the queue
queue::queue(int x)
{
    size = x;
    Q = new int[size];
    front = 0; // Initialize front to 0
    rear = 0;  // Initialize rear to 0
}

// Method to enqueue an element into the queue
void queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Full!" << endl;
    }
    else
    {
        Q[rear] = x;
        rear = (rear + 1) % size; // Increment rear circularly
    }
}

// Method to dequeue an element from the queue
int queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    else
    {
        int x = Q[front];
        front = (front + 1) % size; // Increment front circularly
        return x;
    }
}

// Method to display the elements of the queue
void queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue: ";
        int i = front;
        do
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != rear);
        cout << endl;
    }
}

// Method to get the front element of the queue
int queue::queueFront()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return -1;
    }
    else
    {
        return Q[front];
    }
}

// Method to get the rear element of the queue
int queue::queueRear()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return -1;
    }
    else
    {
        return Q[(rear - 1 + size) % size]; // Return the last element, handling circular wrap-around
    }
}

// Destructor to clean up the allocated memory
queue::~queue()
{
    delete[] Q;
}

// Method to check if the queue is full
bool queue::isFull()
{
    return (rear + 1) % size == front; // Queue is full if next position of rear is front
}

// Method to check if the queue is empty
bool queue::isEmpty()
{
    return front == rear; // Queue is empty if front and rear are the same
}

int main()
{
    int x = 0;
    int choice;
    cout << "Enter size: ";
    cin >> x;
    queue queue1(x);
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
