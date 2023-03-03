/*
Author - Shantanu Wable

Create an inordered threaded binary tree. Perform inorder, preorder traversals without 
recursion and deletion of a node.
Analyze time and space complexity of algorithm.

Ref - https://www.geeksforgeeks.org/double-threaded-binary-search-tree/
*/

#include <iostream>
using namespace std;

class Node
{
    Node *left;
    bool lt;
    int data;
    bool rt;
    Node *right;

    Node()
    {
        left = right = NULL;
        data = 0;
        lt = rt = 0;
    }

    Node(int d)
    {
        left = right = NULL;
        data = d;
        lt = rt = 0;
    }
    
    friend class TBST;
};

class TBST
{
    Node *root;

    TBST()
    {
        cout<<"Enter value of root node: ";
        cin>>root->data;
        cout<<"TBT Created with root as "<<root->data<<endl;
    }

    void insertNode(int d, Node *n);
    Node* inorderSuccessor(Node* root, Node* x);
    Node* leftMostNode(Node* node);
    Node* rightMostNode(Node* node);
    Node* findInorderRecursive(Node* root, Node* x );
    
    void inorder();
    void preorder();
}

int main()
{
    return 0;
}

void TBST::insertNode(int d, Node *n)
{
    Node *temp;
    temp = n;
    Node *t = new Node(d);

    if(d > temp->data)
    {
        if(temp->right == NULL)
            temp->right = t;
        
        else insertNode(d, temp->right);
    }

    else
    {
        if(temp->left == NULL)
            temp->left = t;

        else insertNode(d, temp->left);
    }

    temp->right = inorderSuccessor(root, temp);

}

// function to find left most node in a tree
Node* TBST::leftMostNode(Node* node)
{
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}
 
// function to find right most node in a tree
Node* TBST::rightMostNode(Node* node)
{
    while (node != NULL && node->right != NULL)
        node = node->right;
    return node;
}
 
// recursive function to find the Inorder Successor
// when the right child of node x is NULL
Node* TBST::findInorderRecursive(Node* root, Node* x )
{
    if (!root)
        return NULL;
 
    if (root==x || (temp = findInorderRecursive(root->left,x)) ||
                   (temp = findInorderRecursive(root->right,x)))
    {
        if (temp)
        {
            if (root->left == temp)
            {
                return root;
            }
        }

        return root;
    }
    return NULL;
}
 
// function to find inorder successor of
// a node
Node* TBST::inorderSuccessor(Node* root, Node* x)
{
    // Case1: If right child is not NULL
    if (x->right != NULL)
    {
        Node* inorderSucc = leftMostNode(x->right);
        return inorderSucc;
    }
 
    // Case2: If right child is NULL
    if (x->right == NULL)
    {   
        Node* rightMost = rightMostNode(root);
 
        // case3: If x is the right most node
        if (rightMost == x)
            return NULL;
        else
            findInorderRecursive(root, x);
    }
}
