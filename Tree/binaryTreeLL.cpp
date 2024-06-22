#include <iostream>
#include <stack>
using namespace std;

// Node structure for the binary tree
class treeNode
{
public:
    treeNode *leftChild;
    int data;
    treeNode *rightChild;
};

// Node structure for the queue used in level order traversal
class node
{
public:
    treeNode *data;
    node *next;
};

// Queue implementation for level order traversal
class queue
{
private:
    node *front;
    node *rear;

public:
    queue();                   // Constructor
    bool isEmpty();            // Method to check if the queue is empty
    void enqueue(treeNode *p); // Method to enqueue a treeNode pointer
    treeNode *dequeue();       // Method to dequeue a treeNode pointer
    treeNode *queueFront();    // Method to get the front element of the queue
    treeNode *queueRear();     // Method to get the rear element of the queue
    ~queue();                  // Destructor
};

// Constructor to initialize the queue
queue::queue()
{
    front = nullptr; // Initialize front to nullptr
    rear = nullptr;  // Initialize rear to nullptr
}

// Method to check if the queue is empty
bool queue::isEmpty()
{
    return front == nullptr;
}

// Method to add an element to the queue
void queue::enqueue(treeNode *p)
{
    node *t = new node; // Allocate new node
    if (t == nullptr)
    {
        cout << "Heap Full" << endl;
        return;
    }
    t->data = p;
    t->next = nullptr;
    if (isEmpty())
    {
        front = rear = t; // If the queue is empty, both front and rear point to the new node
    }
    else
    {
        rear->next = t; // Link the new node at the end of the queue
        rear = t;       // Update rear to point to the new node
    }
}

// Method to remove an element from the queue
treeNode *queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Empty" << endl;
        return NULL; // Return NULL to indicate the queue is empty
    }
    else
    {
        node *p = front;       // Temporarily store the front node
        treeNode *x = p->data; // Retrieve data from front node
        front = front->next;   // Move front to the next node
        delete p;              // Delete the old front node
        if (front == nullptr)
        {
            rear = nullptr; // If the queue is now empty, set rear to nullptr as well
        }
        return x;
    }
}

// Method to get the front element of the queue
treeNode *queue::queueFront()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return NULL; // Return NULL to indicate the queue is empty
    }
    else
    {
        return front->data; // Return the front element's data
    }
}

// Method to get the rear element of the queue
treeNode *queue::queueRear()
{
    if (isEmpty())
    {
        cout << "Queue Empty!" << endl;
        return NULL; // Return NULL to indicate the queue is empty
    }
    else
    {
        return rear->data; // Return the rear element's data
    }
}

// Destructor to clean up the allocated memory
queue::~queue()
{
    node *p = front;
    while (front != nullptr)
    {
        front = front->next; // Move to next node
        delete p;            // Delete current node
        p = front;           // Update current node to next node
    }
}

// Class for binary tree operations
class BinaryTree
{
private:
    treeNode *root;
    void preorderrecursive(treeNode *p);
    void inorderrecursive(treeNode *p);
    void postorderrecursive(treeNode *p);
    void destroyTree(treeNode *p);
public:
    BinaryTree();                  // Constructor
    void create();                 // Method to create the binary tree
    void preorderIterative();      // Method for iterative preorder traversal
    void inorderIterative();       // Method for iterative inorder traversal
    void postorderIterative();     // Method for iterative postorder traversal
    void preorderrecursiveCall();  // Method to call recursive preorder traversal
    void inorderrecursiveCall();   // Method to call recursive inorder traversal
    void postorderrecursiveCall(); // Method to call recursive postorder traversal
    void levelorderIterative();
    ~BinaryTree();
};

// Constructor to initialize the BinaryTree
BinaryTree::BinaryTree()
{
    root = nullptr; // Initialize root to nullptr
}
// Destructor to deallocate memory
BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

// Helper function to recursively deallocate memory
void BinaryTree::destroyTree(treeNode *p)
{
    if (p != nullptr)
    {
        destroyTree(p->leftChild);
        destroyTree(p->rightChild);
        delete p; // Delete the current node
    }
}
// Method to create the binary tree
void BinaryTree::create()
{
    treeNode *p;
    treeNode *t;
    queue q;
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new treeNode;
    root->data = x;
    root->leftChild = NULL;
    root->rightChild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child value of " << p->data << " (If absent enter -1): ";
        cin >> x;
        if (x != -1)
        {
            t = new treeNode;
            t->data = x;
            t->leftChild = NULL;
            t->rightChild = NULL;
            p->leftChild = t;
            q.enqueue(t);
        }
        cout << "Enter right child value of " << p->data << " (If absent enter -1): ";
        cin >> x;
        if (x != -1)
        {
            t = new treeNode;
            t->data = x;
            t->leftChild = NULL;
            t->rightChild = NULL;
            p->rightChild = t;
            q.enqueue(t);
        }
    }
}

// Preorder traversal (iterative)
void BinaryTree::preorderIterative()
{
    if (root == nullptr)
        return;
    stack<treeNode *> st;
    treeNode *p = root;
    while (p != nullptr || !st.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->leftChild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->rightChild;
        }
    }
}

// Inorder traversal (iterative)
void BinaryTree::inorderIterative()
{
    if (root == nullptr)
        return;
    stack<treeNode *> st;
    treeNode *p = root;
    while (p != nullptr || !st.empty())
    {
        if (p != nullptr)
        {
            st.push(p);
            p = p->leftChild;
        }
        else
        {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->rightChild;
        }
    }
}

// Postorder traversal (iterative)
void BinaryTree::postorderIterative()
{
    if (root == nullptr)
        return;
    stack<treeNode *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        treeNode *p = st1.top();
        st1.pop();
        st2.push(p);
        if (p->leftChild != nullptr)
            st1.push(p->leftChild);
        if (p->rightChild != nullptr)
            st1.push(p->rightChild);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

//Iterative levelorder traversal
void BinaryTree::levelorderIterative(){
    treeNode *p = root;
    queue q;
    cout<<p->data<<" ";
    q.enqueue(p);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if(p->leftChild){
            cout<<p->leftChild->data<<" ";
            q.enqueue(p->leftChild);
        }
        if(p->rightChild){
            cout<<p->rightChild->data<<" ";
            q.enqueue(p->rightChild);
        }
    }
    

}
// Recursive preorder traversal
void BinaryTree::preorderrecursive(treeNode *p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        preorderrecursive(p->leftChild);
        preorderrecursive(p->rightChild);
    }
}

// Recursive inorder traversal
void BinaryTree::inorderrecursive(treeNode *p)
{
    if (p != nullptr)
    {
        inorderrecursive(p->leftChild);
        cout << p->data << " ";
        inorderrecursive(p->rightChild);
    }
}

// Recursive postorder traversal
void BinaryTree::postorderrecursive(treeNode *p)
{
    if (p != nullptr)
    {
        postorderrecursive(p->leftChild);
        postorderrecursive(p->rightChild);
        cout << p->data << " ";
    }
}

// Method to call recursive preorder traversal
void BinaryTree::preorderrecursiveCall()
{
    preorderrecursive(root);
}

// Method to call recursive inorder traversal
void BinaryTree::inorderrecursiveCall()
{
    inorderrecursive(root);
}

// Method to call recursive postorder traversal
void BinaryTree::postorderrecursiveCall()
{
    postorderrecursive(root);
}

// Main function
int main()
{
    BinaryTree bt;
    bt.create(); // Create the binary tree

    // Recursive traversals
    cout << "Preorder Traversal (Recursive): ";
    bt.preorderrecursiveCall();
    cout << endl;

    cout << "Inorder Traversal (Recursive): ";
    bt.inorderrecursiveCall();
    cout << endl;

    cout << "Postorder Traversal (Recursive): ";
    bt.postorderrecursiveCall();
    cout << endl;

    // Iterative traversals
    cout << "Preorder Traversal (Iterative): ";
    bt.preorderIterative();
    cout << endl;

    cout << "Inorder Traversal (Iterative): ";
    bt.inorderIterative();
    cout << endl;

    cout << "Postorder Traversal (Iterative): ";
    bt.postorderIterative();
    cout << endl;

    cout << "levelorder Traversal (Iterative): ";
    bt.levelorderIterative();
    cout << endl;
    return 0;
}
