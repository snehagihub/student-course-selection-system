
#include "Enrollment.h"
#include <iostream>
using namespace std;

// Select a course for a student
void selectCourse(int studentId, int courseId)
{
    // Check whether student exists
    Student *s = studentHead;

    while (s != nullptr && s->id != studentId)
    {
        s = s->next;
    }

    if (s == nullptr)
    {
        cout << "Student not found!\n";
        return;
    }

    // Check whether course exists
    Course *c = head;

    while (c != nullptr && c->id != courseId)
    {
        c = c->next;
    }

    if (c == nullptr)
    {
        cout << "Course not found!\n";
        return;
    }

    // Check available seats
    if (c->seats <= 0)
    {
        cout << "No seats available!\n";
        return;
    }

    // Prevent duplicate selection
    Enrollment *e = enrollmentHead;

    while (e != nullptr)
    {
        if (e->studentId == studentId &&
            e->courseId == courseId)
        {
            cout << "Course already selected!\n";
            return;
        }

        e = e->next;
    }

    // Create enrollment node
    Enrollment *newEnrollment = new Enrollment;
    newEnrollment->studentId = studentId;
    newEnrollment->courseId = courseId;
    newEnrollment->next = nullptr;

    if (enrollmentHead == nullptr)
    {
        enrollmentHead = newEnrollment;
    }
    else
    {
        e = enrollmentHead;

        while (e->next != nullptr)
        {
            e = e->next;
        }

        e->next = newEnrollment;
    }

    c->seats--;

    cout << "Course selected successfully!\n";
    cout << "Seats remaining: " << c->seats << endl;
}


// Display courses selected by a student
void viewSelectedCourses(int studentId)
{
    Student *s = studentHead;

    while (s != nullptr && s->id != studentId)
    {
        s = s->next;
    }

    if (s == nullptr)
    {
        cout << "Student not found!\n";
        return;
    }

    cout << "\n===== SELECTED COURSES =====\n";

    Enrollment *e = enrollmentHead;
    bool found = false;

    while (e != nullptr)
    {
        if (e->studentId == studentId)
        {
            Course *c = head;

            while (c != nullptr && c->id != e->courseId)
            {
                c = c->next;
            }

            if (c != nullptr)
            {
                cout << c->id << " | "
                     << c->name << endl;

                found = true;
            }
        }

        e = e->next;
    }

    if (!found)
    {
        cout << "This student has not selected any courses.\n";
    }
}


// Drop a selected course
void dropCourse(int studentId, int courseId)
{
    // Check whether student exists
    Student *s = studentHead;

    while (s != nullptr && s->id != studentId)
    {
        s = s->next;
    }

    if (s == nullptr)
    {
        cout << "Student not found!\n";
        return;
    }

    // Find the course
    Course *c = head;

    while (c != nullptr && c->id != courseId)
    {
        c = c->next;
    }

    if (c == nullptr)
    {
        cout << "Course not found!\n";
        return;
    }

    // Find the enrollment
    Enrollment *temp = enrollmentHead;
    Enrollment *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->studentId == studentId &&
            temp->courseId == courseId)
        {
            // Remove enrollment node
            if (prev == nullptr)
            {
                enrollmentHead = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;

            // Restore the available seat
            c->seats++;

            cout << "Course dropped successfully!\n";
            cout << "Seats remaining: "
                 << c->seats << endl;

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Student has not selected this course!\n";
}


// Release enrollment linked-list memory
void freeEnrollments()
{
    Enrollment *temp = enrollmentHead;

    while (temp != nullptr)
    {
        Enrollment *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    enrollmentHead = nullptr;
}
