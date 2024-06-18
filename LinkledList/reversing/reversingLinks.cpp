#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class LinkedList
{
private:
    node *first;

public:
    LinkedList();
    void init();
    void display();
    void reverse();
    ~LinkedList();
};
LinkedList::LinkedList()
{
    first = NULL;
}
void LinkedList::init()
{
    node *t, *last = NULL;
    int n;
    cout << "Enter total no. of elements : ";
    cin >> n;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            t = new node;
            cout << "Enter Element " << i + 1 << " : ";
            cin >> t->data;
            t->next = NULL;
            if (i == 0)
            {
                first = t;
                last = t;
            }
            else
            {
                last->next = t;
                last = t;
            }
        }
    }
}
void LinkedList::reverse()
{
    node *p = first;
    node *q = NULL;
    node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void LinkedList::display()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->data << " "; // printing data of current node
        p = p->next;            // moving to next node
    }
    cout << endl;
}
LinkedList::~LinkedList()
{
    node *p = first;
    while (p != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
int main()
{
    LinkedList ll;
    ll.init();
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}
