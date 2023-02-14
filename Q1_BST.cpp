/*
Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value
*/

#include <iostream>
using namespace std;

class Node
{
    public:
    Node* left;
    int data;
    Node* right;

    Node(int d = 0)
    {
        left = right = NULL;
        data = d;
    }
};

class BST 
{
    public:
    Node *root, *temp;

    void insert_node(int d, Node *n);   //done
    void display(Node *t);              //done
    int find_longest_path();            
    int min_value();                    //done
    int max_value();                    //done
    bool search(int d, Node *n);        //done
    void swap_nodes();
};

int main()
{
    BST tree;
    int choice;
    int flag = 1;
    int d; bool result;
    cout<<"\nEnter root node: ";
    int root;
    cin>>root;
    tree.root->data = root;
    while(flag==1)
    {
        cout<<"~~~~~ BST MENU ~~~~~"<<endl;
        cout<<"1. Insert Node"<<endl;
        cout<<"2. Search for a Node"<<endl;
        cout<<"3. Display BST"<<endl;
        cout<<"4. Display Smallest Value"<<endl;
        cout<<"5. Display largest value"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"Enter element to insert: ";
                    cin>>d;
                    tree.insert_node(d,tree.root);
                    cout<<"Element Inserted!"<<endl;
                    break;
            
            case 2: cout<<"Enter element to search: "<<endl;
                    cin>>d;
                    result = tree.search(d, tree.root);
                    if(result)
                        cout<<"Element Exists in the tree"<<endl;
                    else
                        cout<<"Element not found"<<endl;
                    break;

            case 3: tree.display(tree.root);
                    break;

            case 4: cout<<"Smallest value is: "<<tree.min_value()<<endl;
                    break;
                    
            case 5: cout<<"Largest value is: "<<tree.max_value()<<endl;
                    break;

            default:cout<<"Wrong Input"<<endl;
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
}

void BST::insert_node(int d, Node *n)
{
    Node *temp;
    temp = n;
    Node *t = new Node(d);

    if(d > temp->data)
    {    
        if(temp->right == NULL)
            temp->right = t;
        
        else insert_node(d, temp->right);
    }

    else
    {
        if(temp->left == NULL)
            temp->left = t;

        else insert_node(d, temp->left);
    }
}

bool BST::search(int d, Node *n)
{
    Node *temp;
    temp = n;

    if(d > temp->data)
    {
        if (temp->right == NULL)
            return false;

        else search(d, temp->right);
    }

    else if(d < temp->data)
    {
        if(temp->left == NULL)
            return false;
        
        else search(d, temp->left);
    }

    else return true;
}

int BST::min_value()
{
    Node *temp;
    temp = root;

    while(temp->left != NULL)
        temp = temp->left;
    
    return temp->data;
}

int BST::max_value()
{
    Node *temp;
    temp = root;

    while(temp->right != NULL)
        temp = temp->right;
    
    return temp->data;
}

void BST::display(Node *t)
{
    if(t==NULL)
        return;
    
    display(t->left);
    cout<<t->data<<" ";
    display(t->right);
}