#include <iostream>
#include <vector>
#include <unordered_map>
#include "Student.h"
#include "Course.h"
#include "Utils.h"

using namespace std;

void addStudent(unordered_map<string, Student>& students);
void addCourse(unordered_map<string, Course>& courses);
void enrollStudent(unordered_map<string, Student>& students, unordered_map<string, Course>& courses);
void dropStudent(unordered_map<string, Student>& students, unordered_map<string, Course>& courses);
void printCourse(const unordered_map<string, Course>& courses);

int main() {
    int n;
    cin >> n;

    unordered_map<string, Student> students;
    unordered_map<string, Course> courses;

    while (n--) {
        string command;
        cin >> command;

        if (command == "add_student") {
            addStudent(students);
        } else if (command == "add_course") {
            addCourse(courses);
        } else if (command == "enroll") {
            enrollStudent(students, courses);
        } else if (command == "drop") {
            dropStudent(students, courses);
        } else if (command == "print") {
            printCourse(courses);
        }
        else if (command == "student_courses") {
            printStudentCourses(students);
        }
        else if (command == "search_student") {
            searchStudent(students);
        }
        else if (command == "update_student") {
            updateStudent(students);
        }
    }

    return 0;
}
