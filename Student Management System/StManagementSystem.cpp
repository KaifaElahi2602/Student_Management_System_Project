#include <iostream>
#include <fstream>
#include <string>
using namespace std;




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
