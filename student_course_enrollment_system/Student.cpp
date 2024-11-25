#include "Student.h"
#include <iostream>

void addStudent(unordered_map<std::string, Student>& students) {
    Student s;
    cin >> s.student_id >> s.name >> s.year;
    int m;
    cin >> m;
    while (m--) {
        std::string co;
        cin >> co;
        s.completed_courses.insert(co);
    }
    students[s.student_id] = s;
}