
// Counting Nodes
// Counting Nodes with certain degree
// counting Height
// Finding sum of all elements
#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary tree
class treeNode
{
public:
    treeNode *leftChild;
    int data;
    treeNode *rightChild;
};
class binaryTree
{
private:
    void destroyTree(treeNode *p);

public:
    treeNode *root;
    binaryTree();
    void create();
    int count(treeNode *p);
    int height(treeNode *p);
    int countDeg0(treeNode *p);
    int countDeg1(treeNode *p);
    int countDeg2(treeNode *p);
    int sum(treeNode *p);
    ~binaryTree();
};
binaryTree::binaryTree()
{
    root = nullptr;
}
void binaryTree::create()
{
    treeNode *p;
    treeNode *t;
    queue<treeNode *> q;
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new treeNode;
    root->data = x;
    root->leftChild = NULL;
    root->rightChild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child value of " << p->data << " (If absent enter -1): ";
        cin >> x;
        if (x != -1)
        {
            t = new treeNode;
            t->data = x;
            t->leftChild = NULL;
            t->rightChild = NULL;
            p->leftChild = t;
            q.push(t);
        }else{
            p->leftChild = NULL;
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
            q.push(t);
        }else{
            p->rightChild = NULL;
        }
    }
}
int binaryTree::count(treeNode *p)
{
    int x=0, y=0;
    if (p != NULL)
    {
        x = count(p->leftChild);
        y = count(p->rightChild);
        return x + y + 1;
    }
    return 0;
}
int binaryTree::height(treeNode *p)
{
    int x=0,y=0;
    if(p==0){
        return 0;
    }
    x = height(p->leftChild);
    y = height(p->rightChild);
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }
}
int binaryTree::countDeg0(treeNode *p)
{
    int x=0, y=0;
    if (p != NULL)
    {
        x = countDeg0(p->leftChild);
        y = countDeg0(p->rightChild);
        if (!p->leftChild && !p->rightChild)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int binaryTree::countDeg1(treeNode *p)
{
    int x=0, y=0;
    if (p != NULL)
    {
        x = countDeg1(p->leftChild);
        y = countDeg1(p->rightChild);
        if (p->leftChild && !p->rightChild || !p->leftChild && p->rightChild)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int binaryTree::countDeg2(treeNode *p)
{
    int x=0, y=0;
    if (p != NULL)
    {
        x = countDeg2(p->leftChild);
        y = countDeg2(p->rightChild);
        if (p->leftChild && p->rightChild)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int binaryTree::sum(treeNode *p)
{
    int x=0, y=0;
    if (p != NULL)
    {  
        x = sum(p->leftChild);
        y = sum(p->rightChild);
        return x + y + p->data;
    }
    return 0;
}
// Helper function to recursively deallocate memory
void binaryTree::destroyTree(treeNode *p)
{
    if (p != nullptr)
    {
        destroyTree(p->leftChild);
        destroyTree(p->rightChild);
        delete p; // Delete the current node
    }
}
binaryTree::~binaryTree()
{
    destroyTree(root);
}
int main() {
    binaryTree bt;
    bt.create(); // Create the tree

    cout << "Total number of nodes: " << bt.count(bt.root) << endl;
    cout << "Height of the tree: " << bt.height(bt.root) << endl;
    cout << "Number of leaf nodes (Degree 0): " << bt.countDeg0(bt.root) << endl;
    cout << "Number of nodes with degree 1: " << bt.countDeg1(bt.root) << endl;
    cout << "Number of nodes with degree 2: " << bt.countDeg2(bt.root) << endl;
    cout << "Sum of all nodes: " << bt.sum(bt.root) << endl;

    return 0;
}