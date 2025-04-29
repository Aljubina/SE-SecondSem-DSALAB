#include <iostream>
#include <string>
using namespace std;

class Dictionary 
{
    struct Node {
        string keyword;
        string meaning;
        Node* left;
        Node* right;
        int height;
    };

    Node* root = nullptr;

    int height(Node* node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node* node)
    {
        return node ? height(node->left)-height(node->right) : 0;
    }

    Node* createNode(string key, string meaning)
    {
        Node* node = new Node{key, meaning, nullptr, nullptr, 1};
        return node;
    }

    Node* rotateRight(Node* y)
    {
        //Before rotation 
        Node* x = y->left;
        Node* T2 = x->right;

        //after rotation
        x->right = y;
        y->left = T2;

        //update the height of x and y
        y->height = max(height(y->left) , height(y->right)) + 1;
        x->height = max(height(x->left) , height(x->right)) + 1;


        //new root node
        return x;
    }

    Node* rotateLeft(Node* x)
    {
        //Before rotation 
        Node* y = x->right;
        Node* T2 = y->left;

        //after rotation
        y->left = x;
        x->right = T2;

        //update the height of x and y
        x->height = max(height(x->left) , height(x->right)) + 1;
        y->height = max(height(y->left) , height(y->right)) + 1;


        //new root node
        return y;
    }

    Node* insert(Node* node, string key, string meaning)
    {
        if(!node)
            return createNode(key, meaning);

        if(key < node->keyword)
            node->left = insert(node->left, key, meaning);
        else if (key > node->keyword)
            node->right = insert(node->right, key, meaning);
        else 
        {
            cout<<"Keyword already exit/ update the meaning";
            node->meaning = meaning;
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        //Balancing
        //LL CASE ---> sol : Right Rotate
        if(balance > 1 && key < node->left->keyword)
            return rotateRight(node);

        //RR CASE ---> sol : Left Rotate
        else if(balance < -1 && key > node->right->keyword)
            return rotateLeft(node);

        //LR case --> sol : Rotate Left Then Right
        else if(balance > 1 && key > node->left->keyword )
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        //RL case --> sol : Rotate Right Then Left
        else if(balance < -1 && key < node->right->keyword)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValue(Node* node)
    {
        while(node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, string key)
    {
        if(!root)
            return root;

        if(key < root->keyword)
            root->left = deleteNode(root->left, key);
        else if(key > root->keyword)
            root->right = deleteNode(root->right, key);
        else
        {
            if(!root->left || !root->right)
            {
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            } 
            else 
            {
                Node* temp = minValue(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        if(!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        //LL case: sol-> Right rota
        if(balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        // LR case : sol-> Left then right rotat
        if(balance > 1 && getBalance(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        //RR case: sol-> Left rotate
        if(balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        //RL case : sol-> right left rot
        if(balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inOrder(Node* node)
    {
        if(node)
        {
            inOrder(node->left);
            cout << node->keyword <<":"<<node->meaning<<endl;
            inOrder(node->right);
        }
    }

    void reverseInorder(Node* node)
    {
        if(node)
        {
            reverseInorder(node->right);
            cout << node->keyword <<":"<<node->meaning<<endl;
            reverseInorder(node->left);
        }

    }

    void search(Node* node, string key, int& comparisons)
    {
        while(node)
        {
            comparisons++;
            if(key == node->keyword)
            {
                cout<<"found "<<key<<" with meaning : "<<node->meaning<<endl;
                cout<<"comparisons: "<<comparisons<<endl;
                return;
            } else if(key < node->keyword)
            {
                node = node->left;
            }
            else
                node = node->right;
        }

        cout<<"Keyword not found. Comparisons : "<<comparisons<<endl;
    }

    public :
    void insert(string key, string meaning) {
        root = insert(root, key, meaning);
    }

    void deleteKeyword(string key) {
        root = deleteNode(root, key);
    }

    void displayAscending() {
        cout << "\n--- Dictionary in Ascending Order ---\n";
        inOrder(root);
    }

    void displayDescending() {
        cout << "\n--- Dictionary in Descending Order ---\n";
        reverseInorder(root);
    }

    void search(string key) {
        int comparisons = 0;
        search(root, key, comparisons);
    }

    int maxComparisons() {
        return height(root);
    }

    
};

int main()
{
    Dictionary dict;
    int choice;
    string key, meaning;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Add/Update Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Display Ascending\n";
        cout << "4. Display Descending\n";
        cout << "5. Search Keyword\n";
        cout << "6. Max Comparisons to Find Any Keyword\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter keyword: ";
            getline(cin, key);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            dict.insert(key, meaning);
            break;
        case 2:
            cout << "Enter keyword to delete: ";
            getline(cin, key);
            dict.deleteKeyword(key);
            break;
        case 3:
            dict.displayAscending();
            break;
        case 4:
            dict.displayDescending();
            break;
        case 5:
            cout << "Enter keyword to search: ";
            getline(cin, key);
            dict.search(key);
            break;
        case 6:
            cout << "Maximum comparisons (Tree Height): " << dict.maxComparisons() << endl;
            break;
        case 0:
            cout << "Exiting.....!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}