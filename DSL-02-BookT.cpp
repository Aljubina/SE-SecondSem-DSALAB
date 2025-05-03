#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode 
{
    public :
    string label;
    vector<TreeNode*> children;

    TreeNode(string lbl) {
        label = lbl;
    }

    void addChild(TreeNode* child)
    {
        children.push_back(child);
    }

    //Recursive print function 
    //level controls indentation
    void print(int level = 0) 
    {
        for(int i = 0; i < level; i++)
            cout<<" ";
        cout << label <<endl;
        for(auto child : children)
        {
            child->print(level+1);
        }
    }
};

int main()
{
    TreeNode* book = new TreeNode("Book");

    string bookTitle;
    cout << "Enter name of book: ";
    cin.ignore();
    getline(cin, bookTitle);
    

    int numChapters;
    cout << "Enter number of chapters : ";
    cin >> numChapters;

    for(int i = 0; i < numChapters; i++)
    {
        string chapTitle;
        cout << "Enter name of chapter " << i+1 << ": ";
        cin.ignore();
        getline(cin, chapTitle);

        TreeNode* chapter = new TreeNode("Chapter : " + chapTitle);

        int numSections;
        cout << "Enter number of sections in " << chapTitle << ": ";
        cin >> numSections;

        for(int j = 0; j < numSections; j++)
        {
            string sectionTitle;
            cout << "Enter name of section "<< j+1 <<": ";
            cin.ignore();
            getline(cin, sectionTitle);

            TreeNode* section = new TreeNode("Section : "+ sectionTitle);

            int numSubsec;
            cout << "Enter number of subsections in " << sectionTitle << ": ";
            cin>>numSubsec;

            for(int k = 0; k < numSubsec; k++)
            {
                string subsecTitle;
                cout << "Enter name of subsection "<<k+1 << ": ";
                cin.ignore();
                getline(cin, subsecTitle);

                TreeNode* subsection = new TreeNode("Subsection :" + subsecTitle);
                
                section->addChild(subsection);
            }
            chapter->addChild(section);
        }
        book->addChild(chapter);
    }

    cout << "\nBook Structure : " <<endl ;
    cout << bookTitle << " : " << endl;
    book->print();

    return 0;
}