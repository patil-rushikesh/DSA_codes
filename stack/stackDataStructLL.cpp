#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class stack
{
private:
    node *top;
    int size;

public:
    stack();
    void push(int);
    int pop();
    int peek(int);
    int stackTop();
    int isEmpty();
    int isFull();
    void display();
    ~stack();
};

stack::stack()
{
    top = NULL;
}

void stack::push(int x)
{
    node *t = new node;
    t->data = x;
    t->next = NULL;
    if (t == NULL)
    {
        cout << "stack overflow!" << endl;
    }
    else
    {
        if (top == NULL)
        {
            top = t;
        }
        else
        {
            t->next = top;
            top = t;
        }
    }
}
int stack::pop()
{
    node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int stack::peek(int pos)
{
    node *p = top;
    while (pos-1)
    {
        p = p->next;
        pos = pos - 1;
    }
    return p->data;
}
int stack::stackTop()
{
    if (isEmpty())
    {
        cout << "Stack Empty!" << endl;
    }
    else
    {
        return top->data;
    }
}
int stack::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void stack::display()
{
    node *p = top;
    if (isEmpty())
    {
        cout << "Stack Empty!" << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
}
stack::~stack()
{
    node *p = top;
    while (p != NULL)
    {
        top = top->next;
        delete p;
        p = top;
    }
}
int main()
{
    int temp;
    stack s;
    int choice = 0;
    while (1)
    {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Stack Top\n5. Display\n6. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> temp;
            s.push(temp);
            s.display();
            break;
        case 2:
            temp = s.pop();
            cout << "Element Poped  : " << temp << endl;
            s.display();
            break;
        case 3:
            cout << "Enter Position : ";
            cin >> temp;
            cout << "Element peeked : " << s.peek(temp) << endl;
            break;
        case 4:
            cout << "Element at top : " << s.stackTop() << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            cout << "Exiting the program !" << endl;
            return 0;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }
}