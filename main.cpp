
#include <iostream>
#include <string>
 #include "Course.h"
#include <fstream>
#include "Student.h"
#include "Enrollment.h"
using namespace std;
 
 
Enrollment *enrollmentHead = nullptr;
 
 

  

void addCourse(int id, string name, int credits, int seats)
{
    Course *temp = head;

    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            cout << "Course ID already exists!\n";
            return;
        }
        temp = temp->next;
    }

    Course *newNode = new Course;
    newNode->id = id;
    newNode->name = name;
    newNode->credits = credits;
    newNode->seats = seats;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Course added successfully!\n";
}

void displayCourses()
{
    Course *temp = head;

    if (temp == nullptr)
    {
        cout << "No courses available.\n";
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->id << " | "
             << temp->name << " | Credits: "
             << temp->credits << " | Seats: "
             << temp->seats << endl;

        temp = temp->next;
    }
}

void searchCourse(int id)
{
    Course *temp = head;

    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            cout << "Course found: " << temp->name << endl;
            cout << "Credits: " << temp->credits << endl;
            cout << "Seats: " << temp->seats << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found!\n";
}

void updateCourse(int id)
{
    Course *temp = head;

    while (temp != nullptr && temp->id != id)
        temp = temp->next;

    if (temp == nullptr)
    {
        cout << "Course not found!\n";
        return;
    }

    string name;
    int credits, seats;

    cout << "Enter new course name: ";
    cin >> name;

    cout << "Enter new credits: ";
    cin >> credits;

    cout << "Enter new seats: ";
    cin >> seats;

    if (credits <= 0 || seats < 0)
    {
        cout << "Invalid details! Update rejected.\n";
        return;
    }

    temp->name = name;
    temp->credits = credits;
    temp->seats = seats;

    cout << "Course updated successfully!\n";
}
  
void freeMemory()
{
    while (head != nullptr)
    {
        Course *temp = head;
        head = head->next;
        delete temp;
    }
}  

void saveCourses()
{
    ofstream file("courses.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    Course* temp = head;

    while (temp != nullptr)
    {
        file << temp->id << " "
             << temp->name << " "
             << temp->credits << " "
             << temp->seats << endl;

        temp = temp->next;
    }

    file.close();

    cout << "Courses saved successfully!\n";
}
bool loadCourses()
{
    ifstream file("courses.txt");

    if (!file)
    {
        return false;
    }

    int id, credits, seats;
    string name;
    bool loaded = false;

    while (file >> id >> name >> credits >> seats)
    {
        addCourse(id, name, credits, seats);
        loaded = true;
    }

    file.close();
    return loaded;
}
void saveStudents()
{
    ofstream file("students.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    Student* temp = studentHead;

    while (temp != nullptr)
    {
        file << temp->id << " "
             << temp->name << endl;

        temp = temp->next;
    }

    file.close();
    cout << "Students saved successfully!\n";
}
 bool loadStudents()
{
    ifstream file("students.txt");

    if (!file)
    {
        return false;
    }

    int id;
    string name;
    bool loaded = false;

    while (file >> id >> name)
    {
        registerStudent(id, name);
        loaded = true;
    }

    file.close();
    return loaded;
}
void saveEnrollments()
{
    ofstream file("enrollments.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    Enrollment* temp = enrollmentHead;

    while (temp != nullptr)
    {
        file << temp->studentId << " "
             << temp->courseId << endl;

        temp = temp->next;
    }

    file.close();
    cout << "Enrollments saved successfully!\n";
}
 void loadEnrollments()
{
    ifstream file("enrollments.txt");

    if (!file)
    {
        return;
    }

    int studentId, courseId;

    while (file >> studentId >> courseId)
    {
        Enrollment* temp = new Enrollment;

        temp->studentId = studentId;
        temp->courseId = courseId;
        temp->next = nullptr;

        if (enrollmentHead == nullptr)
        {
            enrollmentHead = temp;
        }
        else
        {
            Enrollment* p = enrollmentHead;

            while (p->next != nullptr)
            {
                p = p->next;
            }

            p->next = temp;
        }
    }

    file.close();
}
 
void searchCourseByName(string name)
{
    Course* temp = head;

    while (temp != nullptr)
    {
        if (temp->name == name)
        {
            cout << "Course Found!\n";
            cout << "Course ID: " << temp->id << endl;
            cout << "Course Name: " << temp->name << endl;
            cout << "Credits: " << temp->credits << endl;
            cout << "Available Seats: " << temp->seats << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found!\n";
}
 
void sortCoursesByCredits()
{
    if (head == nullptr)
    {
        cout << "No courses available!\n";
        return;
    }

    int count = 0;
    Course* temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    Course** arr = new Course*[count];

    temp = head;
    for (int i = 0; i < count; i++)
    {
        arr[i] = temp;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j]->credits > arr[j + 1]->credits)
            {
                Course* t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    cout << "\nCourses sorted by credits:\n";

    for (int i = 0; i < count; i++)
    {
        cout << "ID: " << arr[i]->id
             << " | Name: " << arr[i]->name
             << " | Credits: " << arr[i]->credits
             << " | Seats: " << arr[i]->seats << endl;
    }

    delete[] arr;
}
void sortCoursesByName()
{
    if (head == nullptr)
    {
        cout << "No courses available!\n";
        return;
    }

    int count = 0;
    Course* temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    Course** arr = new Course*[count];

    temp = head;

    for (int i = 0; i < count; i++)
    {
        arr[i] = temp;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j]->name > arr[j + 1]->name)
            {
                Course* t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    cout << "\nCourses sorted alphabetically:\n";

    for (int i = 0; i < count; i++)
    {
        cout << arr[i]->id << " "
             << arr[i]->name << " "
             << arr[i]->credits << " credits, "
             << arr[i]->seats << " seats\n";
    }

    delete[] arr;
}
void viewStudentsInCourse(int courseId)
{
    Course* c = head;

    while (c != nullptr && c->id != courseId)
    {
        c = c->next;
    }

    if (c == nullptr)
    {
        cout << "Course not found!\n";
        return;
    }

    cout << "\nStudents enrolled in " << c->name << ":\n";

    Enrollment* e = enrollmentHead;
    bool found = false;

    while (e != nullptr)
    {
        if (e->courseId == courseId)
        {
            Student* s = studentHead;

            while (s != nullptr && s->id != e->studentId)
            {
                s = s->next;
            }

            if (s != nullptr)
            {
                cout << "Student ID: " << s->id
                     << " | Name: " << s->name << endl;
                found = true;
            }
        }

        e = e->next;
    }

    if (!found)
    {
        cout << "No students enrolled in this course.\n";
    }
}
void showSummary()
{
    int totalStudents = 0;
    int totalCourses = 0;
    int totalEnrollments = 0;

    Student* s = studentHead;
    while (s != nullptr)
    {
        totalStudents++;
        s = s->next;
    }

    Course* c = head;
    while (c != nullptr)
    {
        totalCourses++;
        c = c->next;
    }

    Enrollment* e = enrollmentHead;
    while (e != nullptr)
    {
        totalEnrollments++;
        e = e->next;
    }

    cout << "\n===== SYSTEM SUMMARY =====\n";
    cout << "Total Students: " << totalStudents << endl;
    cout << "Total Courses: " << totalCourses << endl;
    cout << "Total Enrollments: " << totalEnrollments << endl;
}
int main()
{ if (!loadCourses())
{
    addCourse(101, "C", 4, 40);
    addCourse(201, "DSA", 4, 35);
    addCourse(202, "CPP", 3, 30);
}
loadStudents(); 
loadEnrollments();
 
    int choice, id, credits, seats;
    string name;

    do
    {
        cout << "\n===== COURSE MANAGEMENT =====\n";
        cout << "1. Display Courses\n";
        cout << "2. Add Course\n";
        cout << "3. Search Course\n";

        cout << "4. Update Course\n";
        cout << "5. Delete Course\n";
        cout << "6. Exit\n";
        cout << "7. Register Student\n";
        cout << "8. Display Students\n";
        cout << "9. Select Course\n";
        cout << "10. View Selected Courses\n";
        cout << "11. Drop Course\n";
        cout << "12. Save Courses to File\n";
        cout << "13. Save Students to File\n";
        cout << "14. Save Enrollments to File\n";
        cout << "15. Search Student by ID\n";
        cout << "16. Search Course by Name\n";
        cout << "17. Sort Courses by Credits\n";
        cout << "18. Sort Courses by Name\n";
        cout << "19. View Students in a Course\n";
        cout << "20. View System Summary\n";
        cout << "Enter choice: ";
        if (!(cin >> choice))
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Invalid input! Please enter a number.\n";
    continue;
}

      
switch (choice)
{
case 1:
    displayCourses();
    break;

case 2:
    cout << "Enter course ID: ";
    cin >> id;
    cout << "Enter course name (one word): ";
    cin >> name;
    cout << "Enter credits and seats: ";
    cin >> credits >> seats;

    if (credits <= 0 || seats < 0)
        cout << "Invalid credits or seats!\n";
    else
        addCourse(id, name, credits, seats);
    break;

case 3:
    cout << "Enter course ID: ";
    cin >> id;
    searchCourse(id);
    break;

case 4:
    cout << "Enter course ID to update: ";
    cin >> id;
    updateCourse(id);
    break;

case 5:
    cout << "Enter course ID to delete: ";
    cin >> id;
    deleteCourse(id);
    break;

 case 6:
    saveCourses();
    saveStudents();
    saveEnrollments();

    cout << "All data saved successfully!\n";
    cout << "Exiting program...\n";
    break;

case 7:
{
    int studentId;
    string studentName;

    cout << "Enter student ID: ";
    cin >> studentId;
    cout << "Enter student name (one word): ";
    cin >> studentName;

    registerStudent(studentId, studentName);
    break;
}

case 8:
    displayStudents();
    break;

case 9:
{
    int studentId, courseId;

    cout << "Enter student ID: ";
    cin >> studentId;
    cout << "Enter course ID: ";
    cin >> courseId;

    selectCourse(studentId, courseId);
    break;
}
case 10:
{
    int studentId;

    cout << "Enter student ID: ";
    cin >> studentId;

    viewSelectedCourses(studentId);
    break;
}
case 11:
{
    int studentId, courseId;

    cout << "Enter student ID: ";
    cin >> studentId;

    cout << "Enter course ID to drop: ";
    cin >> courseId;

    dropCourse(studentId, courseId);
    break;
}
case 12:
    saveCourses();
    break;
    case 13:{
    saveStudents();
    break;}
    case 14:{
    saveEnrollments();
    break;
    }
    case 15:
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    searchStudent(id);
    break;
}
case 16:
{
    string name;

    cout << "Enter Course Name: ";
    cin >> name;

    searchCourseByName(name);
    break;
}
case 17:
    sortCoursesByCredits();
    break;
    case 18:
    sortCoursesByName();
    break;
    case 19:
{
    int courseId;
    cout << "Enter Course ID: ";
    cin >> courseId;

    viewStudentsInCourse(courseId);
    break;
}
case 20:
    showSummary();
    break;
default:
    cout << "Invalid choice!\n";
}

    } while (choice != 6);
freeMemory();
freeStudents();
freeEnrollments();
 
 
    return 0;
}
