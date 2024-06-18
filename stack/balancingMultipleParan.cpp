#include <iostream>
using namespace std;

class stack {
public:
    int size;
    int top;
    char *s;
    stack(int);
    void push(char);
    char pop();
    char peek(int);
    char stackTop();
    int isEmpty();
    int isFull();
    void display();
    ~stack();
};

stack::stack(int x) {
    size = x;
    s = new char[size];
    top = -1;
}

void stack::push(char x) {
    if (isFull()) {
        cout << "Stack Full!" << endl;
        return;
    } else {
        top++;
        s[top] = x;
    }
}

char stack::pop() {
    char x = '\0';
    if (isEmpty()) {
        x = '\0';
    } else {
        x = s[top];
        top--;
    }
    return x;
}

char stack::peek(int pos) {
    char x = '\0';
    if (top - pos + 1 < 0) {
        cout << "Invalid Position !" << endl;
    } else {
        x = s[top - pos + 1];
    }
    return x;
}

char stack::stackTop() {
    if (isEmpty()) {
        return '\0';
    } else {
        return s[top];
    }
}

int stack::isEmpty() {
    return top == -1;
}

int stack::isFull() {
    return top == size - 1;
}

void stack::display() {
    cout << "Stack: " << endl;
    if (isEmpty()) {
        cout << "Stack Empty !" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << s[i] << endl;
        }
    }
}

stack::~stack() {
    delete[] s;
}

class balancingParanthesis {
private:
    char *A;

public:
    balancingParanthesis();
    void getstr();
    bool isbalancing();
    ~balancingParanthesis();
};

balancingParanthesis::balancingParanthesis() {
    A = new char[100];
}

void balancingParanthesis::getstr() {
    cout << "Enter Equation: " << endl;
    cin >> A;
}

bool balancingParanthesis::isbalancing() {
    stack s(100);
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[') {
            s.push(A[i]);
        } else if (A[i] == ')' || A[i] == '}' || A[i] == ']') {
            if (s.isEmpty()) {
                return false;
            }
            char top = s.pop();
            if ((A[i] == ')' && top != '(') ||
                (A[i] == '}' && top != '{') ||
                (A[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

balancingParanthesis::~balancingParanthesis() {
    delete[] A;
}

int main() {
    balancingParanthesis x;
    x.getstr();
    if (x.isbalancing()) {
        cout << "Equation balanced!" << endl;
    } else {
        cout << "Not Balanced!" << endl;
    }
    return 0;
}
