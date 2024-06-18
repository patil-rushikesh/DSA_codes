#include <iostream>
using namespace std;

class node {
public:
    node *prev;
    int data;
    node *next;
};

class LinkedList {
private:
    node *first;

public:
    LinkedList();
    void create();
    int count();
    void reverse();
    void display();
    ~LinkedList();
};

LinkedList::LinkedList() {
    first = NULL;
}

int LinkedList::count() {
    int count = 0;
    node *p = first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void LinkedList::create() {
    node *t, *last = NULL;
    cout << "Enter the size  : ";
    int n;
    cin >> n;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            t = new node;
            t->prev = NULL;
            t->next = NULL;
            cout << "Enter element " << i + 1 << " : ";
            cin >> t->data;
            if (i == 0) {
                first = t;
                last = t;
            } else {
                t->prev = last;
                last->next = t;
                last = t;
            }
        }
    }
}

void LinkedList::reverse() {
    node *p = first;
    node *temp = NULL;

    while (p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        // If temp is NULL, we have reached the end and p is the new head
        if (temp == NULL) {
            first = p;
        }

        p = p->prev;  // This moves to the next node in the original list
    }
}

void LinkedList::display() {
    node *p = first;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

LinkedList::~LinkedList() {
    node *p = first;
    while (p != NULL) {
        first = first->next;
        delete p;
        p = first;
        if (first) {
            first->prev = NULL;
        }
    }
}

int main() {
    LinkedList ll;
    ll.create();
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}
