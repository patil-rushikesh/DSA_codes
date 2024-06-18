#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class linkedlist {
private:
    node* first;

public:
    linkedlist() {
        first = NULL;
    }

    void create(int A[], int n);
    void display(node* p);
    void rdisplay(node* p); //recursive display
    node* getfirst() {
        return first;
    }

    ~linkedlist();
};

void linkedlist::create(int A[], int n) {
    node* last, * t;
    first = new node;
    first->data = A[0];
    first->next = first;
    last = first;
    for (int i = 1; i < n; i++) {
        t = new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void linkedlist::display(node* p) {
    node* temp = p;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != p);
    cout << endl;
}

void linkedlist::rdisplay(node* p) {
    static int flag = 0;
    if (p != first || flag == 0) {
        flag = 1;
        cout << p->data << " ";
        rdisplay(p->next);
    }
    flag = 0;
}

linkedlist::~linkedlist() {
    if (first == NULL) return;
    node* p = first;
    first = first->next;
    p->next = NULL; // Break the circular reference
    p = first;
    while (p != NULL) {
        first = first->next;
        delete p;
        p = first;
    }
}

int main() {
    int n;
    cout << "Enter size : " << endl;
    cin >> n;
    int A[n];
    cout << "Insert elements in linked list : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    linkedlist l;
    l.create(A, n);
    cout << "Displaying circular linked list : " << endl;
    l.display(l.getfirst());
    cout << "Displaying linked list by recursive function : " << endl;
    l.rdisplay(l.getfirst());
    return 0;
}
