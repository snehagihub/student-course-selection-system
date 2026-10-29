
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    Student *next;
};

extern Student *studentHead;

void registerStudent(int id, string name);
void displayStudents();
void freeStudents();
void searchStudent(int id);
#endif
