#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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


}



int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore(); 

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: cout << "Bye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}

