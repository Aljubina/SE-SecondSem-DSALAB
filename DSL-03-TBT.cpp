#include <iostream>
using namespace std;

class ThreadedNode
{
    public :
    
    //Node structure
    int data;
    bool thLeft, thRight;
    ThreadedNode *left, *right;

    //Initialize using Constructor
    ThreadedNode(int value)
    {
        data = value;
        thLeft = thRight = true;
        left = right = nullptr;
    }

    //Function Declaration
    ThreadedNode* create(ThreadedNode* root);
    void insert(ThreadedNode* root, ThreadedNode* temp);
    void inorderDisplay(ThreadedNode* root);
    void preorderDisplay(ThreadedNode* root);
};

ThreadedNode* ThreadedNode::create(ThreadedNode* root)
{
    char ans;
    do{
        int value;
        cout << "Enter the data : " ;
        cin >> value;
        ThreadedNode* temp = new ThreadedNode(value);

        if(root == nullptr)
            root = temp;
        else 
            insert(root, temp);

        cout << "Add another Node? (y/n) : ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');

    return root;
}

void ThreadedNode::insert(ThreadedNode* root, ThreadedNode* temp)
{
    char ch;
    cout << "Insert to Left or Right of "<< root->data << " (l/r) : ";
    cin >> ch;

    if(ch == 'l' || ch == 'L')
    {
        if(root->thLeft)
        {
            temp->left = root->left;
            temp->right = root;
            root->left = temp;
            root->thLeft = false;
        }
        else {
            insert(root->left, temp);
        }
    }
    else if(ch == 'r' || ch == 'R')
    {
        if(root->thRight)
        {
            temp->right = root->right;
            temp->left = root;
            root->right = temp;
            root->thRight = false;
        }
        else {
            insert(root->right, temp);
        }
    }
}

void ThreadedNode::inorderDisplay(ThreadedNode* root)
{

    if(root == nullptr) return;
    ThreadedNode* temp = root;

    while(temp != nullptr)
    {

        while(!temp->thLeft)
            temp = temp->left;

        cout << temp->data << "\t";

        while(temp->thRight)
        {
            temp = temp->right;
            if(temp == nullptr) return;
            cout << temp->data << "\t";

        }
            
        temp = temp->right;

    }
}

void ThreadedNode::preorderDisplay(ThreadedNode* root)
{
    if(root == nullptr) return;
    ThreadedNode* temp = root;

    while(temp != nullptr)
    {
        cout << temp->data << "\t";

        if(!temp->thLeft)
        {
            temp = temp->left;
        }
        else if (!temp->thRight)
        {
            temp = temp->right;
        }
        else {
            while (temp != nullptr && temp->thRight)
                temp = temp->right;
            if (temp != nullptr)
                temp = temp->right;
        }
    }
}

int main()
{
    ThreadedNode* root = nullptr;
    ThreadedNode helper(0);
    int choice;

    while(true)
    {
        cout << "\n1. Create Threaded Binary Tree\n2. Inorder Display\n3. Preorder Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: 
                root = helper.create(root);
                break;
            case 2:
                cout << "\nInorder Traversal : \n";
                helper.inorderDisplay(root);
                cout << endl;
                break;
            case 3:
                cout << "\nPreorder Traversal:\n";
                helper.preorderDisplay(root);
                cout << endl;
                break;
            case 4:
                cout<<"Exiting...."
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}