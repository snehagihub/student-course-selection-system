
#include <iostream>
#include <string>
using namespace std;

struct Course {
    int id;
    string name;
    int credits;
    int seats;
};

int main() {
    Course courses[5] = {
        {101, "C Programming", 4, 40},
        {201, "Data Structures", 4, 35},
        {202, "C++ Programming", 3, 30},
        {301, "Advanced DSA", 4, 25},
        {302, "Database Systems", 4, 40}
    };

    int choice;

    do {
        cout << "\n===== STUDENT COURSE SELECTION =====\n";
        cout << "1. Display Courses\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nID\tCourse\t\tCredits\tSeats\n";

            for (int i = 0; i < 5; i++) {
                cout << courses[i].id << "\t"
                     << courses[i].name << "\t"
                     << courses[i].credits << "\t"
                     << courses[i].seats << endl;
            }
        }
        else if (choice == 2) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 2);

    return 0;
}
