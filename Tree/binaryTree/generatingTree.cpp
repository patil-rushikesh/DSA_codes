#include <iostream>
#include <queue>
using namespace std;

// Class representing a node in the binary tree
class treeNode {
public:
    treeNode *leftChild;
    int data;
    treeNode *rightChild;
};

// Class representing the binary tree
class binaryTree {
    treeNode *root; // Root node of the tree

    // Helper functions for building the tree
    treeNode* InPre(int *inorder, int *preorder, int inStart, int inEnd, int &preIndex);
    treeNode* InPost(int *inorder, int *postorder, int inStart, int inEnd, int &postIndex);
    void destroyTree(treeNode *p); // Helper function to destroy the tree

public:
    binaryTree(); // Constructor
    void InPre(); // Public function to build the tree using inorder and preorder
    void InPost(); // Public function to build the tree using inorder and postorder
    void display(); // Public function to display the tree
    ~binaryTree(); // Destructor
};

// Constructor to initialize the root to nullptr
binaryTree::binaryTree() {
    root = nullptr;
}

// Helper function to recursively destroy the tree
void binaryTree::destroyTree(treeNode *p) {
    if (p != nullptr) {
        destroyTree(p->leftChild);
        destroyTree(p->rightChild);
        delete p;
    }
}

// Public function to build the tree using inorder and preorder arrays
void binaryTree::InPre() {
    int x;
    cout << "No. of Nodes: ";
    cin >> x;
    int *inorder = new int[x];
    int *preorder = new int[x];
    cout << "Enter the Inorder:" << endl;
    for (int i = 0; i < x; i++) {
        cin >> inorder[i];
    }
    cout << "Enter the Preorder:" << endl;
    for (int i = 0; i < x; i++) {
        cin >> preorder[i];
    }
    int preIndex = 0; // Start index for preorder
    root = InPre(inorder, preorder, 0, x - 1, preIndex); // Build the tree
    delete[] inorder;
    delete[] preorder;
}

// Recursive helper function to build the tree using inorder and preorder arrays
treeNode* binaryTree::InPre(int inorder[], int preorder[], int inStart, int inEnd, int &preIndex) {
    if (inStart > inEnd) return nullptr; // Base case

    treeNode *node = new treeNode;
    node->data = preorder[preIndex++]; // Get the current node from preorder
    node->leftChild = node->rightChild = nullptr; // Initialize children to nullptr

    if (inStart == inEnd) return node; // Leaf node case

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == node->data) {
            inIndex = i;
            break;
        }
    }

    node->leftChild = InPre(inorder, preorder, inStart, inIndex - 1, preIndex); // Build left subtree
    node->rightChild = InPre(inorder, preorder, inIndex + 1, inEnd, preIndex); // Build right subtree

    return node;
}

// Public function to build the tree using inorder and postorder arrays
void binaryTree::InPost() {
    int x;
    cout << "No. of Nodes: ";
    cin >> x;
    int *inorder = new int[x];
    int *postorder = new int[x];
    cout << "Enter the Inorder:" << endl;
    for (int i = 0; i < x; i++) {
        cin >> inorder[i];
    }
    cout << "Enter the Postorder:" << endl;
    for (int i = 0; i < x; i++) {
        cin >> postorder[i];
    }
    int postIndex = x - 1; // Start index for postorder
    root = InPost(inorder, postorder, 0, x - 1, postIndex); // Build the tree
    delete[] inorder;
    delete[] postorder;
}

// Recursive helper function to build the tree using inorder and postorder arrays
treeNode* binaryTree::InPost(int inorder[], int postorder[], int inStart, int inEnd, int &postIndex) {
    if (inStart > inEnd) return nullptr; // Base case

    treeNode *node = new treeNode;
    node->data = postorder[postIndex--]; // Get the current node from postorder
    node->leftChild = node->rightChild = nullptr; // Initialize children to nullptr

    if (inStart == inEnd) return node; // Leaf node case

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == node->data) {
            inIndex = i;
            break;
        }
    }

    node->rightChild = InPost(inorder, postorder, inIndex + 1, inEnd, postIndex); // Build right subtree
    node->leftChild = InPost(inorder, postorder, inStart, inIndex - 1, postIndex); // Build left subtree

    return node;
}

// Function to display the tree using level-order traversal
void binaryTree::display() {
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

// Destructor to destroy the tree and free memory
binaryTree::~binaryTree() {
    destroyTree(root);
}

// Main function to interact with the user and build/display the tree
int main() {
    int x;
    cout << "1. Inorder and Preorder \n2. Inorder and Postorder\n";
    cout << "Enter your choice: ";
    cin >> x;
    binaryTree bt;
    if (x == 1) {
        bt.InPre();
    } else if (x == 2) {
        bt.InPost();
    } else {
        cout << "Invalid Choice";
        return 0;
    }
    bt.display();
    return 0;
}
