
#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "Student.h"
#include "Course.h"

void selectCourse(int studentId, int courseId);
void viewSelectedCourses(int studentId);
void dropCourse(int studentId, int courseId);
void freeEnrollments();
#endif
