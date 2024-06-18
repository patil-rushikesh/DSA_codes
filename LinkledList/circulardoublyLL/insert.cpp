#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
};

class linkedlist
{
private:
    node *head;

public:
    linkedlist()
    {
        head = NULL;
    }

    void create(int A[], int n);
    void display();
    void insertFirst(int x);
    void insertLast(int x);
    void insertAtPosition(int x, int pos);
    bool isEmpty();
    ~linkedlist();
};

void linkedlist::create(int A[], int n)
{
    if (isEmpty())
    {
        head = new node;
        head->prev = head;
        head->data = A[0];
        head->next = head; // Assigning head to head->next to create a circular linked list
        node *last = head;
        for (int i = 1; i < n; i++)
        {
            node *t = new node;
            t->prev = last;
            last->next = t;
            t->data = A[i];
            t->next = head;
            head->prev = t;
            last = t;
        }
    }
    else
    {
        cout << "Linked list already exists." << endl;
    }
}

void linkedlist::display()
{
    if (isEmpty())
    {
        cout << "Linked list is empty." << endl;
        return;
    }
    node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void linkedlist::insertFirst(int x)
{
    node *t = new node;
    t->data = x;
    t->next = NULL;
    if (isEmpty())
    {
        head->prev = head;
        head = t;
        head->next = head;
    }
    else
    {
        node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        t->prev = last;
        last->next = t;

        t->next = head;
        head->prev = t;
        head = t;
    }
}

void linkedlist::insertLast(int x)
{
    node *t = new node;
    t->prev = NULL;
    t->data = x;
    t->next = NULL;
    if (isEmpty())
    {
        head -> prev = head;
        head = t;
        head->next = head;
    }
    else
    {
        node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = t;
        t->prev = last;
        t->next = head;
        head -> prev = t;
        last = t;
    }
}

void linkedlist::insertAtPosition(int x, int pos)
{
    node *t = new node;
    t->prev = NULL;
    t->data = x;
    t->next = NULL;
    if (isEmpty())
    {
        head->prev = head;
        head = t;
        head->next = head;
    }
    else
    {
        node *last = head;
        for (int i = 0; i < pos - 2; i++)
        {
            last = last->next;
        }
        last->next->prev = t;
        t->next = last ->next;
        last -> next = t;
        t->prev = last;
    }
}

bool linkedlist::isEmpty()
{
    return head == NULL;
}

linkedlist::~linkedlist()
{
    if (isEmpty())
        return;
    node *p = head;
    head = head->next;
    p->next = NULL; // Break the circular reference
    p = head;
    while (p != NULL)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    int A[n];
    cout << "Insert elements in circular linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    linkedlist l;
    l.create(A, n);
    cout << "Displaying linked list: ";
    l.display();

    int element;
    cout << "Enter element to insert at first: ";
    cin >> element;
    l.insertFirst(element);
    cout << "Linked list after inserting at first: ";
    l.display();

    cout << "Enter element to insert at last: ";
    cin >> element;
    l.insertLast(element);
    cout << "Linked list after inserting at last: ";
    l.display();

    int pos;
    cout << "Enter element and position to insert at: ";
    cin >> element >> pos;
    l.insertAtPosition(element, pos);
    cout << "Linked list after inserting at position " << pos << ": ";
    l.display();

    return 0;
}
