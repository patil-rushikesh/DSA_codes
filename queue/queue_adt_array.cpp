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
    front = -1;
    rear = -1;
}

void queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Full!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        Q[rear] = x;
    }
}

int queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
    {
        int x = Q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
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
        for (int i = front; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

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
int queue::queueRear()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return -1;
    }
    else
    {
        return Q[rear];
    }
}

queue::~queue()
{
    delete[] Q;
}

bool queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool queue::isEmpty()
{
    return front == -1;
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
