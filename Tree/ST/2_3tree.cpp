#include <iostream>
using namespace std;

// Define the structure of a tree node
class treeNode {
public:
    int data1;            // First data element in the node
    int data2;            // Second data element in the node (used if the node has two keys)
    treeNode *leftChild;  // Pointer to the left child
    treeNode *midChild;   // Pointer to the middle child
    treeNode *rightChild; // Pointer to the right child

    // Constructor for initializing a node
    treeNode(int val) {
        data1 = val;
        data2 = 0;
        leftChild = midChild = rightChild = nullptr;
    }
};

// Define the structure of the tree
class tree {
    treeNode *root;

    // Helper function to recursively destroy the tree
    void destroy(treeNode *node);

    // Helper function for finding the minimum value in the subtree
    treeNode *findMin(treeNode *node);

    // Helper function for deleting a key
    treeNode *deleteKey(treeNode *node, int key);

    void display(treeNode *node, int depth);

    void insert(treeNode *&node, int key, treeNode *&parent);

public:
    tree();
    void insert(int key);
    void deleteNode(int key);
    void display();
    ~tree();
};

// Tree constructor
tree::tree() {
    root = nullptr;
}

// Function to insert a key into the tree
void tree::insert(int key) {
    if (root == nullptr) {
        root = new treeNode(key);
    } else {
        treeNode *parent = nullptr;
        insert(root, key, parent);
    }
}

void tree::insert(treeNode *&current, int key, treeNode *&parent) {
    if (current == nullptr) {
        current = new treeNode(key);
        if (parent) {
            if (key < parent->data1) {
                parent->leftChild = current;
            } else if (parent->data2 == 0 || key < parent->data2) {
                parent->midChild = current;
            } else {
                parent->rightChild = current;
            }
        }
    } else {
        if (current->data2 == 0) { // current is a 2-node
            if (key < current->data1) {
                current->data2 = current->data1;
                current->data1 = key;
            } else {
                current->data2 = key;
            }
        } else { // current is a 3-node and needs splitting
            treeNode *newChild = nullptr;
            int newKey;

            if (key < current->data1) {
                newKey = current->data1;
                newChild = new treeNode(current->data2);
                current->data1 = key;
            } else if (key < current->data2) {
                newKey = key;
                newChild = new treeNode(current->data2);
            } else {
                newKey = current->data2;
                newChild = new treeNode(key);
            }

            current->data2 = 0;

            if (parent == nullptr) { // current is root
                treeNode *newRoot = new treeNode(newKey);
                newRoot->leftChild = current;
                newRoot->midChild = newChild;
                root = newRoot;
            } else {
                insert(parent, newKey, current);
                if (key < parent->data1) {
                    parent->leftChild = current;
                    parent->midChild = newChild;
                } else if (parent->data2 == 0 || key < parent->data2) {
                    parent->midChild = newChild;
                } else {
                    parent->rightChild = newChild;
                }
            }
        }
    }
}

// Function to display the tree structure
void tree::display() {
    display(root, 0);
}

void tree::display(treeNode *node, int depth) {
    if (node != nullptr) {
        // Indent based on the depth of the node
        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }

        // Display the node
        cout << "[";
        cout << node->data1;
        if (node->data2 != 0) {
            cout << ", " << node->data2;
        }
        cout << "]" << endl;

        // Recursively display the children
        display(node->leftChild, depth + 1);
        display(node->midChild, depth + 1);
        display(node->rightChild, depth + 1);
    }
}

// Helper function to recursively destroy the tree
void tree::destroy(treeNode *node) {
    if (node == nullptr)
        return;

    destroy(node->leftChild);
    destroy(node->midChild);
    destroy(node->rightChild);
    delete node;
}

// Destructor for the tree
tree::~tree() {
    destroy(root);
}

// Helper function to find the minimum value in a subtree
treeNode *tree::findMin(treeNode *node) {
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;
}

// Helper function to delete a key from the tree
treeNode *tree::deleteKey(treeNode *node, int key) {
    // Placeholder for deletion logic. To be implemented.
    cout << "Deletion of key " << key << " not implemented." << endl;
    return node;
}

// Function to delete a key from the tree
void tree::deleteNode(int key) {
    root = deleteKey(root, key);
}

int main() {
    tree t;
    t.insert(21);
    t.insert(30);
    t.insert(10);
    t.insert(18);
    t.insert(25);
    t.insert(34);
    t.insert(6);
    t.insert(15);
    t.insert(20);
    t.insert(22);
    t.insert(40);
    t.insert(33);

    cout << "Tree before deletion: " << endl;
    t.display();
    cout << endl;

    t.deleteNode(18);
    t.deleteNode(25);

    cout << "Tree after deletion: " << endl;
    t.display();
    cout << endl;

    return 0;
}
