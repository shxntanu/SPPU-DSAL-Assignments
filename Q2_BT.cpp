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
public:
    Node *left;
    int data;
    Node *right;
    
    Node(int d)
    {
        left = NULL;
        data = d;
        right = NULL;
    }
    
    Node()
    {
        left = NULL;
        data = 0;
        right = NULL;
    }
};

Node* buildTree(Node *root)
{
    cout<<"Enter data for node (-1 indicates no data): ";
    int d;
    cin>>d;
    root = new Node(d);
    
    if(d == -1)
        return NULL;
    
    cout<<"Enter data to the left of "<<d;
    root->left = buildTree(root->left);
    cout<<"Enter data to the right of "<<d;
    root->right = buildTree(root->right);
    return root;
}

void nodeSwap(Node *root)
{
    if(root)
    {
        if(root->left || root->right)
        {
            Node *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        nodeSwap(root->right);
        nodeSwap(root->left);
    }
}

void rpostorder(Node *root)
{
    if(root == NULL)
        return;

    rpostorder(root->left);
    rpostorder(root->right);
    cout<<root->data<<" ";
}

void rpreorder(Node *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    rpreorder(root->left);
    rpreorder(root->right);
}

void rinorder(Node *root)
{
    if(root == NULL)
        return;

    rinorder(root->left);
    cout<<root->data<<" ";
    rinorder(root->right);
}

void iinorder(Node *root)
{
    stack<Node*> s;
    Node *curr = root;
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

void ipreorder(Node *root)
{
    stack<Node*> s;
    Node *curr = root;
    s.push(root);
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

void ipostorder(Node *root)
{
    stack<Node*> s1, s2;
    s1.push(root);
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

int height(Node* root)
{
    if(root == NULL) return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return max(h1,h2)+1;
}

int dia(Node* root)
{
    if(root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);

    int op1 = dia(root->left);
    int op2 = dia(root->right);
    int op3 = l+r+1;

    return max(op1,max(op2,op3));
}

int getLeafCount(Node *root)
{
    if(root == NULL)
        return 0;
    else if(root->left == NULL and root->right == NULL)
        return 1;
    else
        return getLeafCount(root->right) + getLeafCount(root->left);
}

int getInternalNodes(Node *root)
{
    if(root == NULL or (root->right == NULL and root->left == NULL))
        return 0;
    else return 1 + getInternalNodes(root->left) + getInternalNodes(root->right);
}

void deleteTree(Node* root)
{
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    cout << "\n Deleting node: " << root->data;
    delete root;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int flag = 1, choice1;
    while(flag)
    {
        int choice;
        cout<<"======================================="<<endl;
        cout<<"||                                   ||"<<endl;
        cout<<"||       ~~~~~ BST MENU ~~~~~        ||"<<endl;
        cout<<"||                                   ||"<<endl;
        cout<<"||       1. Display BST              ||"<<endl;
        cout<<"||       2. Swap all nodes           ||"<<endl;
        cout<<"||       3. Height of tree           ||"<<endl;
        cout<<"||       4. Number of leaf nodes     ||"<<endl;
        cout<<"||       5. Number of internal nodes ||"<<endl;
        cout<<"||       6. Delete all nodes         ||"<<endl;
        cout<<"||                                   ||"<<endl;
        cout<<"======================================="<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"\t1. Recursive Inorder\n\t2. Iterative Inorder\n\t3. Recursive Preorder\n\t4. Iterative Preorder\n\t5. Recursive Postorder\n\t6. Iterative Postorder\n\tEnter your choice: ";
                cin>>choice1;
                switch(choice1)
                {
                    case 1:
                        rinorder(root);
                        break;
                        
                    case 2:
                        iinorder(root);
                        break;
                        
                    case 3:
                        rpreorder(root);
                        break;
                        
                    case 4:
                        ipreorder(root);
                        break;
                        
                    case 5:
                        rpostorder(root);
                        break;
                        
                    case 6:
                        ipostorder(root);
                        break;
                        
                    default:
                        cout<<"Wrong Input!"<<endl;
                }
                break;
                
            case 2:
                nodeSwap(root);
                cout<<"Nodes swapped!, Inorder Display: "<<endl;
                iinorder(root);
                break;
                
            case 3:
                cout<<"Height of tree: "<<dia(root);
                break;
                
            case 4:
                cout<<"Number of leaf nodes: "<<getLeafCount(root)<<endl;
                break;
                
            case 5:
                cout<<"Number of internal nodes: "<<getInternalNodes(root);
                break;
                
            case 6:
                deleteTree(root);
                break;
                
            default:
                cout<<"Wrong input!"<<endl;
        }
    
        label:
        cout<<"\nDo you want to perform another operation? (1/0): ";
        cin>>flag;
        if(flag == 1)
            continue;
        else if(flag == 0)
            break;
        else
        {
            cout<<"Wrong input, try again!";
            goto label;
        }
    }
    return 0;
}
