#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class LinkedList {
private:
    node* first;

public:
    LinkedList();
    LinkedList& operator=(const LinkedList& other); // Assignment operator
    void init();
    void display();
    friend LinkedList concatenate(LinkedList&, LinkedList&);
    ~LinkedList();
    void clear();
};

LinkedList::LinkedList() : first(NULL) {}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    if (other.first != NULL) {
        node* p = other.first;
        node* last = NULL;
        while (p != NULL) {
            node* t = new node;
            t->data = p->data;
            t->next = NULL;
            if (first == NULL) {
                first = t;
                last = t;
            } else {
                last->next = t;
                last = t;
            }
            p = p->next;
        }
    }
    return *this;
}

void LinkedList::init() {
    node* t, * last;
    int n;
    cout << "Enter total no. of elements: ";
    cin >> n;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            t = new node;
            cout << "Enter element " << i + 1 << ": ";
            cin >> t->data;
            t->next = NULL;
            if (i == 0) {
                first = t;
                last = t;
            } else {
                last->next = t;
                last = t;
            }
        }
    }
}

void LinkedList::display() {
    node* p = first;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::clear() {
    node* p = first;
    while (p != NULL) {
        node* temp = p;
        p = p->next;
        delete temp;
    }
    first = NULL;
}

LinkedList concatenate(LinkedList& ll1, LinkedList& ll2) {
    LinkedList ll3;
    if (ll1.first == NULL) {
        ll3.first = ll2.first;
    } else {
        ll3.first = ll1.first;
        node* p = ll1.first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ll2.first;
    }
    // Clear the pointers of the source lists to avoid double deletion in destructor
    ll1.first = NULL;
    ll2.first = NULL;
    return ll3;
}

int main() {
    LinkedList a, b, c;
    a.init();
    cout << "List A: ";
    a.display();
    b.init();
    cout << "List B: ";
    b.display();
    c = concatenate(a, b);
    cout << "Concatenated List: ";
    c.display();
    return 0;
}
