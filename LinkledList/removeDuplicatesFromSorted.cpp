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
    bool isSorted();
    void removeDuplicates();
    void display();
    ~LinkedList();
};
LinkedList::LinkedList()
{
    first = NULL;
}
void LinkedList::init()
{
    int n;
    cout << "Enter total no. of elements : ";
    cin >> n;
    node *t, *last = NULL;
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
void LinkedList ::display()
{
    node *p = first;
    while(p!=NULL){
        cout<<p -> data<<" ";
        p = p -> next;
    }
    cout<<endl;
}
bool LinkedList::isSorted(){
    int x = INT32_MIN;
    node *p = first;
    while(p != NULL){
        if(p -> data  < x){
            return false;
        }
        x = p -> data;
        p = p -> next;
    }
    return true;
}
void LinkedList::removeDuplicates(){
    node *p = first;
    node *q = first -> next;
    while(q != NULL){
        if(p -> data != q -> data){
            p = q;
            q = q->next;
        }else{
            p->next  = q->next;
            delete q;
            q = p -> next;
        }
    }
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
int main(){
    LinkedList ll;
    ll.init();
    ll.display();
    ll.removeDuplicates();
    ll.display();
    return 0;
}