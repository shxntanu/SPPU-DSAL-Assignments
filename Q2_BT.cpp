/*
Author - Shantanu Wable

Beginning with an empty binary tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree, perform the
following operations on it -
1. Perform inorder, preorder and postorder traversal
2. Change a tree so that the roles of the left and right pointers are swapped at every node
3. Find the height of the tree
4. Copy this tree to another tree (operator =)
5. Count number of leaves, number of internal nodes
6. Erase all nodes in a binary tree

(implement both recursive and iterative methods)
*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
    Node *left;
    int data;
    Node *right;
    public:
    Node(int d=0)
    {
        int d=0;
        left = right = NULL;
    }

    friend class BT;
};

class BT
{
    Node *root = new Node();

    public:
    BT()
    {
        int d;
        cout<<"Enter value of root node of tree";
        cin>>d;
        root->data = d;
    }

    void insert(Node *n, int d);
    void inorder(Node *node);
    void preorder(Node *node);
    void postorder(Node *node);
    void swap(Node *node);
    int height(Node* node);
    int dia(Node* node);

    BT(BT *t)
    {
        this->root = t->root;
    }
};

void BT::insert(Node *n, int d)
{
    Node *temp = new Node(d);
    if(n->left == NULL)
    {
        n->left = temp;
        cout<<"Node Inserted"<<endl;
        return;
    }

    
}

void BT::swap(Node *node)
{
    if(node)
    {
        if(node->left || node->right)
        {
            Node *temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        swap(node->right);
        swap(node->left);
    }
}

int BT::height(Node* node)
{
    if(node == NULL) return 0;

    int h1 = height(node->left);
    int h2 = height(node->right);

    return max(h1,h2)+1;
}

int BT::dia(Node* node)
{
    if(node == NULL) return 0;

    int l = height(node->left);
    int r = height(node->right);

    int op1 = dia(node->left);
    int op2 = dia(node->right);
    int op3 = l+r+1;

    return max(op1,max(op2,op3));
}

void BT::postorder(Node *node)
{
    if(node == NULL)
        return;

    inorder(node->left);
    inorder(node->right);
    cout<<node->data<<" ";
}

void BT::preorder(Node *node)
{
    if(node == NULL)
        return;

    cout<<node->data<<" ";
    inorder(node->left);
    inorder(node->right);
}

void BT::inorder(Node *node)
{
    if(node == NULL)
        return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
