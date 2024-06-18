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
    void deleteNode(int index);
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

void LinkedList::deleteNode(int index) {
    if (index <= 0 || index > count()) {
        return;
    }
    node *p = first;  // Initialize p to first
    if (index == 1) {
        first = first->next;
        if (first) {
            first->prev = NULL;
        }
        delete p;  // Delete the old first node
    } else {
        for (int i = 1; i < index; i++) {  // Use i = 1 to properly iterate to the correct index
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next) {
            p->next->prev = p->prev;
        }
        delete p;  // Delete the node at the specified index
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
    ll.deleteNode(2);
    ll.display();
    ll.deleteNode(1);
    ll.display();
    return 0;
}
