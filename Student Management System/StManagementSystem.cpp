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







