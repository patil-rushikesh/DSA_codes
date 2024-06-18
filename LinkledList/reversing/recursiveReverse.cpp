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
    void reverse(node*,node*);
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
void LinkedList::reverse(node *q, node *p)
{
 if(p!=NULL){
    reverse(p, p->next);
    p->next = q;
 }else{
    first = q;
 }   
}
void LinkedList::reverse(){
    reverse(NULL, first);
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
