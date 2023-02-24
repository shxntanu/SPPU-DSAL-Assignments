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
#include <stack>
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
    void rinorder(Node *node);
    void rpreorder(Node *node);
    void rpostorder(Node *node);
    void iinorder(Node *node);
    void ipreorder(Node *node);
    void ipostorder(Node *node);
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
    Node *newnode = new Node(d);
    if(n==NULL)
        root = newnode;

    else
    {
        queue<Node*> q;
        q.push(n);
    
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
    
            if (temp->left != NULL)
                q.push(temp->left);
            else {
                temp->left = newnode;
            }
    
            if (temp->right != NULL)
                q.push(temp->right);
            else {
                temp->right = newnode;
            }
        }
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

void BT::rpostorder(Node *node)
{
    if(node == NULL)
        return;

    rinorder(node->left);
    rinorder(node->right);
    cout<<node->data<<" ";
}

void BT::rpreorder(Node *node)
{
    if(node == NULL)
        return;

    cout<<node->data<<" ";
    rinorder(node->left);
    rinorder(node->right);
}

void BT::rinorder(Node *node)
{
    if(node == NULL)
        return;

    rinorder(node->left);
    cout<<node->data<<" ";
    rinorder(node->right);
}
  
void BT::iinorder(Node *node)
{
    stack<Node*> s;
    Node *curr = node;
    while(!s.empty() or curr!=NULL)
    {
        if(curr!=NULL)
        {    
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";

        curr = curr->right;
    }
}

void BT::ipreorder(Node *node)
{
    stack<Node*> s;
    Node *curr = node;
    s.push(node);
    while(!s.empty() or curr!=NULL)
    {
        Node *t = s.top();
        s.pop();
        cout<<t->data<<" ";
        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);
    }
}

void BT::ipostorder(Node *node)
{
    stack<Node*> s1, s2;
    s1.push(node);
    while(!s1.empty())
    {
        Node *t = s1.top();
        s1.pop();
        s2.push(t);
        if(t->left)
            s1.push(t->left);
        if(t->right)
            s1.push(t->right);
    }
    while(!s2.empty())
    {   
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

