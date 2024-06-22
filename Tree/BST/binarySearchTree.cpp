#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class treeNode {
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
};

class bst {
private:
    treeNode *root;

    void destroy(treeNode *p);
    treeNode *searchRecursive(treeNode *p, int key);
    treeNode *insertRecursive(treeNode *p, int key);
    treeNode *deleteNode(treeNode *p, int key);
    treeNode *inorderSuccessor(treeNode *p);
    treeNode *inorderPredecessor(treeNode *p);
    int height(treeNode *p);

public:
    bst();
    ~bst();
    void display();
    treeNode* searchIterative(int key);
    treeNode* searchRecursive(int key);
    void insertIterative(int key);
    void insertRecursive(int key);
    void createUsingPreorder(int *preorder, int size);
    void deleteNode(int key);
};

bst::bst() {
    root = nullptr;
}

bst::~bst() {
    destroy(root);
}

void bst::destroy(treeNode *p) {
    if (p != nullptr) {
        destroy(p->leftChild);
        destroy(p->rightChild);
        delete p;
    }
}

int bst::height(treeNode *p) {
    if (p == nullptr) return 0;
    int leftHeight = height(p->leftChild);
    int rightHeight = height(p->rightChild);
    return 1 + max(leftHeight, rightHeight);
}

treeNode* bst::searchIterative(int key) {
    treeNode *p = root;
    while (p != nullptr) {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    return nullptr;
}

treeNode* bst::searchRecursive(treeNode *p, int key) {
    if (p == nullptr || p->data == key)
        return p;
    if (key < p->data)
        return searchRecursive(p->leftChild, key);
    return searchRecursive(p->rightChild, key);
}

treeNode* bst::searchRecursive(int key) {
    return searchRecursive(root, key);
}

void bst::insertIterative(int key) {
    treeNode *t = new treeNode{key, nullptr, nullptr};
    if (root == nullptr) {
        root = t;
        return;
    }

    treeNode *p = root;
    treeNode *parent = nullptr;

    while (p != nullptr) {
        parent = p;
        if (key < p->data)
            p = p->leftChild;
        else if (key > p->data)
            p = p->rightChild;
        else
            return; // Duplicate keys are not allowed
    }

    if (key < parent->data)
        parent->leftChild = t;
    else
        parent->rightChild = t;
}

treeNode* bst::insertRecursive(treeNode *p, int key) {
    if (p == nullptr) {
        treeNode *t = new treeNode{key, nullptr, nullptr};
        return t;
    }
    if (key < p->data)
        p->leftChild = insertRecursive(p->leftChild, key);
    else if (key > p->data)
        p->rightChild = insertRecursive(p->rightChild, key);
    return p;
}

void bst::insertRecursive(int key) {
    root = insertRecursive(root, key);
}

void bst::createUsingPreorder(int *preorder, int size) {
    if (size == 0)
        return;

    root = new treeNode{preorder[0], nullptr, nullptr};
    stack<treeNode*> st;
    treeNode *p = root;

    for (int i = 1; i < size; i++) {
        if (preorder[i] < p->data) {
            p->leftChild = new treeNode{preorder[i], nullptr, nullptr};
            st.push(p);
            p = p->leftChild;
        } else {
            while (!st.empty() && preorder[i] > st.top()->data) {
                p = st.top();
                st.pop();
            }
            p->rightChild = new treeNode{preorder[i], nullptr, nullptr};
            p = p->rightChild;
        }
    }
}

treeNode* bst::inorderSuccessor(treeNode *p) {
    treeNode *current = p->rightChild;
    while (current && current->leftChild != nullptr)
        current = current->leftChild;
    return current;
}

treeNode* bst::inorderPredecessor(treeNode *p) {
    treeNode *current = p->leftChild;
    while (current && current->rightChild != nullptr)
        current = current->rightChild;
    return current;
}

treeNode* bst::deleteNode(treeNode *p, int key) {
    if (p == nullptr)
        return p;
    if (key < p->data)
        p->leftChild = deleteNode(p->leftChild, key);
    else if (key > p->data)
        p->rightChild = deleteNode(p->rightChild, key);
    else {
        if (p->leftChild == nullptr) {
            treeNode *temp = p->rightChild;
            if (p == root) root = temp; // Update root if needed
            delete p;
            return temp;
        } else if (p->rightChild == nullptr) {
            treeNode *temp = p->leftChild;
            if (p == root) root = temp; // Update root if needed
            delete p;
            return temp;
        }
        if (height(p->leftChild) > height(p->rightChild)) {
            treeNode *temp = inorderPredecessor(p);
            p->data = temp->data;
            p->leftChild = deleteNode(p->leftChild, temp->data);
        } else {
            treeNode *temp = inorderSuccessor(p);
            p->data = temp->data;
            p->rightChild = deleteNode(p->rightChild, temp->data);
        }
    }
    return p;
}

void bst::deleteNode(int key) {
    root = deleteNode(root, key);
}

void bst::display() {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }

    queue<treeNode*> q;
    q.push(root);

    while (!q.empty()) {
        treeNode* p = q.front();
        q.pop();

        cout << "Node: " << p->data << endl;

        if (p->leftChild == nullptr) {
            cout << "Left Child: No Left Child" << endl;
        } else {
            cout << "Left Child: " << p->leftChild->data << endl;
            q.push(p->leftChild);
        }

        if (p->rightChild == nullptr) {
            cout << "Right Child: No Right Child" << endl;
        } else {
            cout << "Right Child: " << p->rightChild->data << endl;
            q.push(p->rightChild);
        }
    }
}

int main() {
    bst tree;
    int choice, key;
    int preorder[] = {30, 20, 10, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    while (true) {
        cout << "\n1. Insert Iterative\n2. Insert Recursive\n3. Search Iterative\n4. Search Recursive\n5. Create Using Preorder\n6. Delete\n7. Display\n8. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            tree.insertIterative(key);
            break;
        case 2:
            cout << "Enter key to insert: ";
            cin >> key;
            tree.insertRecursive(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            if (tree.searchIterative(key))
                cout << "Key found." << endl;
            else
                cout << "Key not found." << endl;
            break;
        case 4:
            cout << "Enter key to search: ";
            cin >> key;
            if (tree.searchRecursive(key))
                cout << "Key found." << endl;
            else
                cout << "Key not found." << endl;
            break;
        case 5:
            tree.createUsingPreorder(preorder, size);
            break;
        case 6:
            cout << "Enter key to delete: ";
            cin >> key;
            tree.deleteNode(key);
            break;
        case 7:
            tree.display();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
