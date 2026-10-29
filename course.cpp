
#include "Course.h"
#include <iostream>
using namespace std;
Course *head = nullptr;


// Display details of one course
void displayCourse(Course *course) {
    if (course == nullptr) {
        cout << "Course not found!" << endl;
        return;
    }

    cout << "Course ID: " << course->id << endl;
    cout << "Course Name: " << course->name << endl;
    cout << "Credits: " << course->credits << endl;
    cout << "Available Seats: " << course->seats << endl;
}

void deleteCourse(int id)
{
    Enrollment* e = enrollmentHead;

    while (e != nullptr)
    {
        if (e->courseId == id)
        {
            cout << "Cannot delete: students have selected this course!\n";
            return;
        }

        e = e->next;
    }

    Course *temp = head;
    Course *prev = nullptr;

    while (temp != nullptr && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Course not found!\n";
        return;
    }

    if (prev == nullptr)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Course deleted successfully!\n";
}
