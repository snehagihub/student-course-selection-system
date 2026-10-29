
#include "Student.h"
#include <iostream>
using namespace std;

Student *studentHead = nullptr;

void registerStudent(int id, string name)
{
    Student *temp = studentHead;

    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            cout << "Student ID already exists!\n";
            return;
        }

        temp = temp->next;
    }

    Student *newStudent = new Student;
    newStudent->id = id;
    newStudent->name = name;
    newStudent->next = nullptr;

    if (studentHead == nullptr)
    {
        studentHead = newStudent;
    }
    else
    {
        temp = studentHead;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    cout << "Student registered successfully!\n";
}

void displayStudents()
{
    Student *temp = studentHead;

    if (temp == nullptr)
    {
        cout << "No students registered.\n";
        return;
    }

    while (temp != nullptr)
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name << endl;

        temp = temp->next;
    }
}
void searchStudent(int id)
{
    Student* temp = studentHead;

    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            cout << "Student Found!\n";
            cout << "Student ID: " << temp->id << endl;
            cout << "Student Name: " << temp->name << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found!\n";
}void freeStudents()
{
    Student *temp = studentHead;

    while (temp != nullptr)
    {
        Student *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    studentHead = nullptr;
}