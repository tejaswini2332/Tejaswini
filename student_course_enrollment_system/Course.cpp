#include "Course.h"
#include "Utils.h"
#include <iostream>

void addCourse(unordered_map<std::string, Course>& courses) {
    Course c;
    cin >> c.course_code >> c.course_name >> c.credits >> c.capacity >> c.slot;
    int p;
    cin >> p;
    while (p--) {
        std::string co;
        cin >> co;
        c.prerequisites.insert(co);
    }

    unordered_set<std::string> visited, recursionStack;
    courses[c.course_code] = c;
    if (hasCycle(c.course_code, courses, visited, recursionStack)) {
        courses.erase(c.course_code);
    }
}

void printCourse(const unordered_map<std::string, Course>& courses) {
    string co;
    cin >> co;
    if (courses.find(co) == courses.end()) {
        cout << "Invalid Course " << co << endl;
    } else {
        cout << "Enrolled students in " << co << ":" << endl;
        if (courses.at(co).stu.empty()) {
            cout << "No students enrolled" << endl;
        } else {
            for (const auto& k : courses.at(co).stu) {
                cout << k << " ";
            }
            cout << endl;
        }
    }
}