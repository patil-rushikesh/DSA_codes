#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
};
class LinkedList
{
private:
    node *first;

public:
    LinkedList();
    void create();
    int count();
    void insert(int, int);
    void display();
    ~LinkedList();
};
LinkedList::LinkedList()
{
    first = NULL;
}
int LinkedList::count()
{
    int count = 0;
    node *p = first;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void LinkedList::create()
{
    node *t, *last = NULL;
    cout << "Enter the size  : ";
    int n;
    cin >> n;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            t = new node;
            t->prev = NULL;
            t->next = NULL;
            cout << "Enter element " << i + 1 << " : ";
            cin >> t->data;
            if (i == 0)
            {
                first = t;
                last = t;
            }
            else
            {
                t->prev = last;
                last->next = t;
                last = t;
            }
        }
    }
}
void LinkedList::insert(int index, int x)
{
    if (index < 0 || index > count())
    {
        return;
    }
    node *t;
    t = new node;
    t->data = x;
    if (index == 0)
    {
        t->prev = NULL;
        t->next = first;
        if (first != NULL)
        {
            first->prev = t;
        }
        first = t;
    }
    else
    {
        node *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}
void LinkedList::display()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
LinkedList::~LinkedList()
{
    node *p = first;
    while (p != NULL)
    {
        first = first->next;
        first->prev = NULL;
        delete p;
        p = first;
    }
}
int main()
{
    LinkedList ll;
    ll.create();
    ll.display();
    ll.insert(2, 4);
    ll.insert(0, 5);
    ll.display();
    return 0;
}