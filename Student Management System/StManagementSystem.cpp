#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void addStudent()
{
    string id, roll, name, sclass, contact, address;
    ofstream file("student.txt", ios::app);

    cout << "Enter Student ID: ";
    getline(cin, id);

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Roll No: ";
    getline(cin, roll);

    cout << "Enter Class: ";
    getline(cin, sclass);

    cout << "Enter Contact No: ";
    getline(cin, contact);

    cout << "Enter Address: ";
    getline(cin, address);

    file << id << "," << name << "," << roll << "," 
         << sclass << "," << contact << "," << address << endl;
    file.close();

    cout << "Student Added Successfully!\n";
}




void displayStudents()
{
    string line, id, name, roll, sclass, contact, address;

    ifstream file("student.txt");
    cout << "\n--- STUDENT RECORDS ---\n";

    while (
       
        getline(file, id, ',') &&
        getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, sclass, ',') &&
        getline(file, contact, ',') &&
        getline(file, address) 
       
    )
    {
       

        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll << endl;
        cout << "Class: " << sclass << endl;
        cout << "Contact: " << contact << endl;
        cout << "Address: " << address << endl;
        cout << "----------------------\n";
    }

    file.close();
}

void deleteStudents()
{
    string idDelete;
    cout << "Enter Student ID to delete: ";
    cin>>idDelete;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    string id, name, roll, sclass, contact, address;
    bool found = false;

    while (
        getline(file, id, ',') &&
        getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, sclass, ',') &&
        getline(file, contact, ',') &&
        getline(file, address)
    )
    {
        if (id == idDelete)
        {
            found = true;   
        }
        else
        {
            temp << id << "," << name << "," << roll << ","
                 << sclass << "," << contact << "," << address << endl;
        }
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Student deleted successfully!\n";
    else
        cout << "Student ID not found!\n";
}


void searchStudent()
{
    string idSearch;
    cout<<"Enter Student id you want to search: ";
    cin >> idSearch;
    cin.ignore();

    ifstream file("student.txt");

    string id, name, roll, sclass, contact, address;
    bool found = false;

    while (
        getline(file, id, ',') &&
        getline(file, name, ',') &&
        getline(file, roll, ',') &&
        getline(file, sclass, ',') &&
        getline(file, contact, ',') &&
        getline(file, address)
    )
    {
        if (id == idSearch)
        {
            cout << id << " "
                 << name << " "
                 << roll << " "
                 << sclass << " "
                 << contact << " "
                 << address << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Student ID not found\n";
}

int main()
{
    
    int choice;

    do
    {
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
         cout << "\n3. Delete Students";
        cout << "\n4. Search Students";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Students";
        cout << "\n4. Delete Students";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore(); 

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudents(); break;
            case 4: deleteStudents(); break;
            case 5: cout << "Bye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}

















