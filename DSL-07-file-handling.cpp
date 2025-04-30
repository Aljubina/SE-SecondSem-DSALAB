#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Student structure 
struct Student
{
    int rollNo;
    string name;
    string division;
    string address;
};

void addStudent()
{
    Student s;
    fstream fout("studentInfo.Dat", ios::app);

    cout<<"Enter RollNo : ";
    cin>>s.rollNo;
    cin.ignore();

    cout<<"Enter Name : ";
    getline(cin,s.name);

    cout<<"Enter Division : ";
    getline(cin,s.division);
    

    cout<<"Enter Address : ";
    getline(cin,s.address);
     
    //Writting in file 
    fout << "RollNo: " << s.rollNo << endl;
    fout << "Name: " << s.name << endl;
    fout << "Division: " << s.division << endl;
    fout << "Address: " << s.address << endl;
    fout << "---" << endl;  // separator

    fout.close();

    cout << "Student Record added successfully. \n";
}

void searchStudent()
{
    ifstream fin("studentInfo.Dat");
    string line;
    int rollNoFind;
    bool found = false;

    cout<<"Enter the Roll No to find : ";
    cin>>rollNoFind;

    Student s;
    while(getline(fin, line))
    {
        if(line.find("RollNo:") == 0 )
        {
            s.rollNo = stoi(line.substr(7));
            getline(fin, line); s.name = line.substr(6);
            getline(fin, line); s.division = line.substr(10);
            getline(fin, line); s.address = line.substr(9);
            getline(fin, line);

            if(s.rollNo == rollNoFind)
            {
                cout << "\nStudent Found:\n";
                cout << "RollNo: " << s.rollNo << endl;
                cout << "Name: " << s.name << endl;
                cout << "Division: " << s.division << endl;
                cout << "Address : " << s.address << endl;

                found = true;
                break;
            }
        }
    } 

    if(!found)
    {
        cout << "Student with Roll No " << rollNoFind << " not found\n";
    }
    fin.close();
}

void deleteStudent()
{
    ifstream fin("studentInfo.Dat");
    ofstream temp("temp.Dat");

    string line;
    int rolltoDelete;
    bool found = false;

    cout<<"Enter the roll NO to delete :";
    cin>>rolltoDelete;

    Student s;
    while(getline(fin, line))
    {
        if(line.find("RollNo: ") ==0 )
        {
            s.rollNo = stoi(line.substr(7));
            string nameLine, divLine, addrLine;
            getline(fin, nameLine); s.name = nameLine.substr(6);
            getline(fin, divLine); s.division = divLine.substr(10);
            getline(fin, addrLine); s.address = addrLine.substr(9);
            getline(fin, line);

            if(s.rollNo != rolltoDelete)
            {
                temp << "RollNo: " << s.rollNo << endl;
                temp << "Name: " << s.name << endl;
                temp << "Division: " << s.division << endl;
                temp << "Address: " << s.address << endl;
                temp << "---" << endl;
            }
            else {
                found = true;
            }
        }
    } 

    fin.close();
    temp.close();

    remove("studentInfo.Dat");
    rename("temp.Dat", "studentInfo.Dat");

    if(found)
        cout << "Record deleted successfully.\n";
    else 
        cout << "Student with Roll No " << rolltoDelete << " not found.\n";
}

void displayStudent()
{
    ifstream fin("studentInfo.Dat");
    string line;
    cout << "\n--- Student Records ---\n";
    while(getline(fin, line))
    {
        cout<<line<<endl;
    }

    fin.close();
}

int main()
{
    int choice;
    do {
        cout << "\n--- Student Record Management---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: deleteStudent(); break;
            case 4: displayStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}