#include <iostream>
using namespace std;

class stack {
public:
    int size;
    int top;
    char *s;
    stack(int size = 100);
    void push(char);
    char pop();
    char peek(int);
    char stackTop();
    bool isEmpty();
    bool isFull();
    void display();
    ~stack();
};

stack::stack(int size) {
    this->size = size;
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

bool stack::isEmpty() {
    return top == -1;
}

bool stack::isFull() {
    return top == size - 1;
}

void stack::display() {
    cout << "Stack : " << endl;
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

class postfix {
    char *A;
    char *Result;
    int length;
    stack s;

public:
    postfix();
    void getstr();
    void display();
    int getPrecedence(char);
    bool isOperator(char);
    void convert();
    ~postfix();
};

postfix::postfix() {
    A = new char[100];
    Result = new char[100];
    length = 0;
}

void postfix::getstr() {
    cout << "Enter Infix Expression: " << endl;
    cin.getline(A, 100);
}

void postfix::display() {
    cout << "Postfix Expression: " << Result << endl;
}

int postfix::getPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    } else if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
        return 3;
    } else {
        return 0;
    }
}

bool postfix::isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/';
}

void postfix::convert() {
    int j = 0;
    for (int i = 0; A[i] != '\0'; i++) {
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= '0' && A[i] <= '9')) {
            while (!s.isEmpty() && getPrecedence(s.stackTop()) == 3) {
                Result[j++] = s.pop();
            }
            s.push(A[i]);
        } else if (A[i] == '(') {
            s.push(A[i]);
        } else if (A[i] == ')') {
            while (!s.isEmpty() && s.stackTop() != '(') {
                Result[j++] = s.pop();
            }
            if (!s.isEmpty() && s.stackTop() == '(') {
                s.pop();
            }
        } else if (isOperator(A[i])) {
            while (!s.isEmpty() && getPrecedence(s.stackTop()) >= getPrecedence(A[i])) {
                Result[j++] = s.pop();
            }
            s.push(A[i]);
        }
    }
    while (!s.isEmpty()) {
        Result[j++] = s.pop();
    }
    Result[j] = '\0';
}

postfix::~postfix() {
    delete[] A;
    delete[] Result;
}

int main() {
    postfix p;
    p.getstr();
    p.convert();
    p.display();
    return 0;
}
