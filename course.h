 
#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

struct Course {
    int id;
    string name;
    int credits;
    int seats;
    Course *next;
};

struct Enrollment {
    int studentId;
    int courseId;
    Enrollment *next;
};

extern Course *head;
extern Enrollment *enrollmentHead;

void addCourse(int id, string name, int credits, int seats);
void displayCourses();
void searchCourse(int id);
void updateCourse(int id);
void deleteCourse(int id);

#endif
