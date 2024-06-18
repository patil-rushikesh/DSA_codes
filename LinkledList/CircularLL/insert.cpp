#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class linkedlist {
private:
    node* head;

public:
    linkedlist() {
        head = NULL;
    }

    void create(int A[], int n);
    void display();
    void insertFirst(int x);
    void insertLast(int x);
    void insertAtPosition(int x, int pos);
    bool isEmpty();
    ~linkedlist();
};

void linkedlist::create(int A[], int n) {
    if (isEmpty()) {
        head = new node;
        head->data = A[0];
        head->next = head; // Assigning head to head->next to create a circular linked list
        node* last = head;
        for (int i = 1; i < n; i++) {
            node* t = new node;
            t->data = A[i];
            t->next = last->next; // as last->next is storing the address of head, now t will point to head
            last->next = t;
            last = t;
        }
    }
    else {
        cout << "Linked list already exists." << endl;
    }
}

void linkedlist::display() {
    if (isEmpty()) {
        cout << "Linked list is empty." << endl;
        return;
    }
    node* p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void linkedlist::insertFirst(int x) {
    node* q = new node;
    q->data = x;
    q->next = NULL;
    if (isEmpty()) {
        head = q;
        head->next = head;
    }
    else {
        node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = q;
        q->next = head;
        head = q;
    }
}

void linkedlist::insertLast(int x) {
    node* q = new node;
    q->data = x;
    q->next = NULL;
    if (isEmpty()) {
        head = q;
        head->next = head;
    }
    else {
        node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = q;
        q->next = head;
    }
}

void linkedlist::insertAtPosition(int x, int pos) {
    node* q = new node;
    q->data = x;
    q->next = NULL;
    if (isEmpty()) {
        head = q;
        head->next = head;
    }
    else {
        node* p = head;
        for (int i = 0; i < pos - 2; i++) {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }
}

bool linkedlist::isEmpty() {
    return head == NULL;
}

linkedlist::~linkedlist() {
    if (isEmpty()) return;
    node* p = head;
    head = head->next;
    p->next = NULL; // Break the circular reference
    p = head;
    while (p != NULL) {
        head = head->next;
        delete p;
        p = head;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int A[n];
    cout << "Insert elements in circular linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    linkedlist l;
    l.create(A, n);
    cout << "Displaying linked list: ";
    l.display();
    
    int element;
    cout << "Enter element to insert at first: ";
    cin >> element;
    l.insertFirst(element);
    cout << "Linked list after inserting at first: ";
    l.display();
    
    cout << "Enter element to insert at last: ";
    cin >> element;
    l.insertLast(element);
    cout << "Linked list after inserting at last: ";
    l.display();
    
    int pos;
    cout << "Enter element and position to insert at: ";
    cin >> element >> pos;
    l.insertAtPosition(element, pos);
    cout << "Linked list after inserting at position " << pos << ": ";
    l.display();
    
    return 0;
}
