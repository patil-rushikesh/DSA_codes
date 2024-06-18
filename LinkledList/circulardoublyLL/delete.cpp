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
    void deleteFirstNode();
    void deleteLastNode();
    void deleteNode(int x);
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

void linkedlist::deleteFirstNode()
{
    if (isEmpty())
    {
        cout << "Linked list is empty. Cannot delete." << endl;
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        node *p = head;
        head->next->prev = last;
        last->next = head->next;
        head = head->next;
        delete p;
    }
}

void linkedlist::deleteLastNode()
{
    if (isEmpty())
    {
        cout << "Linked list is empty. Cannot delete." << endl;
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *last = head;
        node *p = NULL;
        while (last->next != head)
        {
            p = last;
            last = last->next;
        }
        p->next = head;
        head->prev = p;
        delete last;
    }
}

void linkedlist::deleteNode(int x)
{
    if (isEmpty())
    {
        cout << "Linked list is empty. Cannot delete." << endl;
        return;
    }
    if (head->data == x)
    {
        deleteFirstNode();
        return;
    }
    node *t = head;
    node *p = NULL;
    do
    {
        p = t;
        t = t->next;
    } while (t != head && t->data != x);
    if (t == head)
    {
        cout << "Node not found." << endl;
        return;
    }
    p->next = t->next;
    t->next->prev = p;
    delete t;
}

bool linkedlist::isEmpty()
{
    return head == NULL;
}

linkedlist::~linkedlist()
{
    while (!isEmpty())
    {
        deleteFirstNode();
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
    int choice;
    while (true)
    {
        cout << "1. Display linked list\n";
        cout << "2. Delete first node\n";
        cout << "3. Delete last node\n";
        cout << "4. Delete a specific node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Display linked list: ";
            l.display();
            break;
        case 2:
            cout << "Deleting first node: ";
            l.deleteFirstNode();
            l.display();
            break;
        case 3:
            cout << "Deleting last node: ";
            l.deleteLastNode();
            l.display();
            break;
        case 4:
            int x;
            cout << "Enter value of node to delete: ";
            cin >> x;
            cout << "Deleting node with value " << x << ": ";
            l.deleteNode(x);
            l.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}
