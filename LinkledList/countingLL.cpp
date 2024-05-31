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
    node *first = NULL;
    int length_rec_m1(node *p);
    int length_rec_m2(node *p);
    int length_rec_m3(node *p);
    int length_rec_m4(node *p);

public:
    LinkedList();
    void init();
    void display();
    int length();
    int length_rec_m1();
    int length_rec_m2();
    int length_rec_m3();
    int length_rec_m4();
    ~LinkedList();
};

LinkedList::LinkedList()
{
    first = new node;
    first->data = 0;
    first->next = NULL;
}

void LinkedList::init()
{
    int n;
    cout << "Enter total no. of elements: ";
    cin >> n;
    node *t, *last = NULL;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            t = new node;
            cout << "Enter Element " << i + 1 << ": ";
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

int LinkedList::length()
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

int LinkedList::length_rec_m1(node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return length_rec_m1(p->next) + 1;
    }
}

int LinkedList::length_rec_m2(node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + length_rec_m2(p->next);
    }
}

int LinkedList::length_rec_m3(node *p)
{
    if (p != NULL)
    {
        return 1 + length_rec_m3(p->next);
    }
    else
    {
        return 0;
    }
}

int LinkedList::length_rec_m4(node *p)
{
    int x = 0;
    if (p != NULL)
    {
        x = length_rec_m4(p->next);
        return x + 1;
    }
    else
    {
        return 0;
    }
}

int LinkedList::length_rec_m1()
{
    return length_rec_m1(first);
}

int LinkedList::length_rec_m2()
{
    return length_rec_m2(first);
}

int LinkedList::length_rec_m3()
{
    return length_rec_m3(first);
}

int LinkedList::length_rec_m4()
{
    return length_rec_m4(first);
}

LinkedList::~LinkedList()
{
    node *p = first;
    while (first)
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
    cout << "Length of the linked list is " << ll.length() << endl;
    cout << "Length of the linked list (rec_m1) is " << ll.length_rec_m1() << endl;
    cout << "Length of the linked list (rec_m2) is " << ll.length_rec_m2() << endl;
    cout << "Length of the linked list (rec_m3) is " << ll.length_rec_m3() << endl;
    cout << "Length of the linked list (rec_m4) is " << ll.length_rec_m4() << endl;
    return 0;
}
