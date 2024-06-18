#include <iostream>
using namespace std;
class stack
{
private:
    int size;
    int top;
    int *s;

public:
    stack(int);
    void push(int);
    int pop();
    int peek(int);
    int stackTop();
    int isEmpty();
    int isFull();
    void display();
    ~stack();
};

stack::stack(int x)
{
    size = x;
    s = new int[size];
    top = -1;
}

void stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Full!" << endl;
        return;
    }
    else
    {
        top++;
        s[top] = x;
    }
}
int stack::pop()
{
    int x = NULL;
    if (isEmpty())
    {
        x = NULL;
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}
int stack::peek(int pos)
{
    int x = NULL;
    if (top - pos + 1 < 0)
    {
        cout << "Invalid Position !" << endl;
    }
    else
    {
        x = s[top - pos + 1];
    }
    return x;
}
int stack::stackTop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        return s[top];
    }
}
int stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stack::isFull()
{
    if (top == size - 1)
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
    cout << "Stack : " << endl;
    if (isEmpty())
    {
        cout << "Stack Empty !" << endl;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << s[i] << endl;
        }
    }
}
stack::~stack()
{
    delete[] s;
}
int main()
{
    int temp;
    stack s(5);
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
        cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
}