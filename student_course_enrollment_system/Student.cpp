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
void printStudentCourses(const unordered_map<string, Student>& students) {
    string studentId;
    cin >> studentId;

    auto it = students.find(studentId);
    if (it == students.end()) return;

    const vector<string>& enrolledCourses = it->second.getEnrolledCourses();
    if (enrolledCourses.empty()) return;

    for (const string& course : enrolledCourses) {
        cout << course << " ";
    }
    cout << endl;
}
void searchStudent(const unordered_map<string, Student>& students) {
    string studentId;
    cin >> studentId;

    auto it = students.find(studentId);
    if (it == students.end()) {
        cout << "Student not found\n";
        return;
    }

    cout << "ID: " << it->second.getId() << "\n";
    cout << "Name: " << it->second.getName() << "\n";
}
void updateStudent(unordered_map<string, Student>& students) {
    string id;
    cin >> id;

    auto it = students.find(id);
    if (it == students.end()) {
        cout << "Student not found\n";
        return;
    }

    string newName;
    cin.ignore();
    getline(cin, newName);
    it->second.setName(newName);
}
