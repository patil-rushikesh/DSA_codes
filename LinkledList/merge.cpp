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
    friend LinkedList merge(LinkedList&, LinkedList&);
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

LinkedList merge(LinkedList& ll1, LinkedList& ll2) {
    LinkedList ll3;
    node* last;
    node* p = ll1.first;
    node* q = ll2.first;

    // If both lists are empty
    if (p == NULL && q == NULL) {
        return ll3;
    }

    // Initialize the first node of the merged list
    if (p == NULL) {
        ll3.first = q;
        return ll3;
    } else if (q == NULL) {
        ll3.first = p;
        return ll3;
    }

    if (p->data < q->data) {
        ll3.first = last = p;
        p = p->next;
    } else {
        ll3.first = last = q;
        q = q->next;
    }
    last->next = NULL;

    // Merge the remaining nodes
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
        } else {
            last->next = q;
            last = q;
            q = q->next;
        }
        last->next = NULL;
    }

    if (p != NULL) {
        last->next = p;
    }
    if (q != NULL) {
        last->next = q;
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
    c = merge(a, b);
    cout << "Merged List: ";
    c.display();
    return 0;
}
