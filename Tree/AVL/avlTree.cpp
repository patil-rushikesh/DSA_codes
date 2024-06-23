#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class treeNode {
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    int height; // height of the node in the tree
};

class avl {
private:
    treeNode *root;

    void destroy(treeNode *p);
    treeNode *insertRecursive(treeNode *p, int key);
    treeNode *deleteNode(treeNode *p, int key);
    int height(treeNode *p);
    int balanceFactor(treeNode *p);
    treeNode *rotateLeft(treeNode *p);
    treeNode *rotateRight(treeNode *p);
    treeNode *rotateLeftRight(treeNode *p);
    treeNode *rotateRightLeft(treeNode *p);
    treeNode *balance(treeNode *p);

public:
    avl();
    ~avl();
    void display();
    treeNode* searchIterative(int key);
    void insertIterative(int key);
    void createUsingPreorder(int *preorder, int size);
    void deleteNode(int key);
};

avl::avl() {
    root = nullptr;
}

avl::~avl() {
    destroy(root);
}

void avl::destroy(treeNode *p) {
    if (p != nullptr) {
        destroy(p->leftChild);
        destroy(p->rightChild);
        delete p;
    }
}

int avl::height(treeNode *p) {
    if (p == nullptr) return 0;
    return p->height;
}

int avl::balanceFactor(treeNode *p) {
    if (p == nullptr) return 0;
    return height(p->leftChild) - height(p->rightChild);
}

treeNode* avl::rotateLeft(treeNode *p) {
    treeNode *p_right = p->rightChild;
    treeNode *p_right_left = p_right->leftChild;

    p_right->leftChild = p;
    p->rightChild = p_right_left;

    // Update heights
    p->height = 1 + max(height(p->leftChild), height(p->rightChild));
    p_right->height = 1 + max(height(p_right->leftChild), height(p_right->rightChild));

    // Update root if needed
    if (root == p) root = p_right;

    return p_right;
}

treeNode* avl::rotateRight(treeNode *p) {
    treeNode *p_left = p->leftChild;
    treeNode *p_left_right = p_left->rightChild;

    p_left->rightChild = p;
    p->leftChild = p_left_right;

    // Update heights
    p->height = 1 + max(height(p->leftChild), height(p->rightChild));
    p_left->height = 1 + max(height(p_left->leftChild), height(p_left->rightChild));

    // Update root if needed
    if (root == p) root = p_left;

    return p_left;
}

treeNode* avl::rotateLeftRight(treeNode *p) {
    p->leftChild = rotateLeft(p->leftChild);
    return rotateRight(p);
}

treeNode* avl::rotateRightLeft(treeNode *p) {
    p->rightChild = rotateRight(p->rightChild);
    return rotateLeft(p);
}

treeNode* avl::balance(treeNode *p) {
    p->height = 1 + max(height(p->leftChild), height(p->rightChild));
    int bf = balanceFactor(p);
    if (bf > 1) {
        if (balanceFactor(p->leftChild) >= 0) {
            return rotateRight(p);
        } else {
            return rotateLeftRight(p);
        }
    } else if (bf < -1) {
        if (balanceFactor(p->rightChild) <= 0) {
            return rotateLeft(p);
        } else {
            return rotateRightLeft(p);
        }
    }
    return p;
}

treeNode* avl::insertRecursive(treeNode *p, int key) {
    if (p == nullptr) {
        treeNode *t = new treeNode{key, nullptr, nullptr, 1};
        return t;
    }
    if (key < p->data)
        p->leftChild = insertRecursive(p->leftChild, key);
    else if (key > p->data)
        p->rightChild = insertRecursive(p->rightChild, key);
    return balance(p);
}

void avl::insertIterative(int key) {
    root = insertRecursive(root, key);
}

void avl::createUsingPreorder(int *preorder, int size) {
    if (size == 0)
        return;
    for (int i = 0; i < size; i++) {
        insertIterative(preorder[i]);
    }
}

treeNode* avl::deleteNode(treeNode *p, int key) {
    if (p == nullptr)
        return p;
    if (key < p->data)
        p->leftChild = deleteNode(p->leftChild, key);
    else if (key > p->data)
        p->rightChild = deleteNode(p->rightChild, key);
    else {
        if (p->leftChild == nullptr || p->rightChild == nullptr) {
            treeNode *temp = p->leftChild ? p->leftChild : p->rightChild;
            if (temp == nullptr) {
                temp = p;
                p = nullptr;
            } else {
                *p = *temp;
            }
            delete temp;
        } else {
            treeNode *temp = p->rightChild;
            while (temp->leftChild != nullptr) {
                temp = temp->leftChild;
            }
            p->data = temp->data;
            p->rightChild = deleteNode(p->rightChild, temp->data);
        }
    }
    if (p == nullptr)
        return p;
    return balance(p);
}

void avl::deleteNode(int key) {
    root = deleteNode(root, key);
}

void avl::display() {
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
    avl tree;
    int choice, key;
    int preorder[] = {30, 20, 10, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    while (true) {
        cout << "\n1. Insert Iterative\n2. Create Using Preorder\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            tree.insertIterative(key);
            break;
        case 2:
            tree.createUsingPreorder(preorder, size);
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            tree.deleteNode(key);
            break;
        case 4:
            tree.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
