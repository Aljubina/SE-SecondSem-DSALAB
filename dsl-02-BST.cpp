#include<iostream>
using namespace std;

class BST {
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    public:
    BST() {
        root = NULL;
    }

    void insert();
    node* insertNode(node* root, int data);
    int longestPath(node* node);
    int getLongestPath();
    int findMin();
    void mirrorTree();
    void mirror(node* root);
    void search();
    bool help_search(node* root, int ele);
    void display();
    void inOrderTraverse(node* root);

};

void BST::insert()
{
    int val;
    cout<<"Enter the value to be inserted : ";
    cin>>val;
    root = insertNode(root, val);

}
BST::node* BST::insertNode(node* root, int val) {
    if(root == NULL) 
    {
        node* newNode  = new node();
        newNode->data = val;
        return newNode; 
    }

    if(val < root->data) {
        root->left = insertNode(root->left, val);
    }
    else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int BST::longestPath(node* node)
{
    if(node == NULL)
    {
        return 0;
    }

    int leftPath = longestPath(node->left);
    int rightPath = longestPath(node->right);

    return max(leftPath, rightPath) + 1;
}

int BST::getLongestPath() 
{
    return longestPath(root);
}

int BST::findMin() 
{
    if(root == NULL) 
    {
        cout<<"Tree is empty";
        return -1;
    }

    node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;

}

void BST::mirrorTree()
{
    mirror(root);
    cout<<"Tree is mirrored";
}

void BST::mirror(node* root)
{
    if(root == NULL)
        return;

    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

void BST::search()
{
    int val;
    cout<<"Enter the value to search :";
    cin>>val;

    if(help_search(root, val))
    {
        cout<<"Value found";
    }
    else 
        cout<<"Not found";
}

bool BST::help_search(node* root, int val)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == val)
        return true;
    if(root->data > val)
    {
        return help_search(root->left, val);
    }
    else
        return help_search(root->right, val);
}

void BST::display()
{
    cout<<"Traversal : ";
    inOrderTraverse(root);
    cout<<endl;
}

void BST::inOrderTraverse(node* root)
{
    if( root == NULL) return;
    inOrderTraverse(root->left);
    cout<<root->data<<" ";
    inOrderTraverse(root->right);
}

int main()
{
    BST tree;
    int choice;
    bool running = true;
    while (running) {
        cout << "\n**** MENU ****" << endl;
        cout << "1: Insert node" << endl;
        cout << "2: Display inorder" << endl;
        cout << "3: Longest path from root" << endl;
        cout << "4: Minimum element" << endl;
        cout << "5: Mirror tree" << endl;
        cout << "6: Search" << endl;
        cout << "0: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            tree.insert();
            break;
        case 2:
            tree.display();
            break;
        case 3:
            cout << "Longest path from root is: " << tree.getLongestPath() << endl;
            break;
        case 4:
            cout << "Minimum value is: " << tree.findMin() << endl;
            break;
        case 5:
            tree.mirrorTree();
            break;
        case 6:
            tree.search();
            break;
        case 0:
            running = false;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}