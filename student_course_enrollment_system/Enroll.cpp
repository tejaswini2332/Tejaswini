#include "Student.h"
#include "Course.h"
#include <iostream>

void enrollStudent(unordered_map<std::string, Student>& students, unordered_map<std::string, Course>& courses) {
    string sid, cc;
    cin >> sid >> cc;
    if (students.find(sid) == students.end() || courses.find(cc) == courses.end()) {
        return;
    }

    auto& prereqs = courses[cc].prerequisites;
    auto& completed = students[sid].completed_courses;

    for (const auto& prereq : prereqs) {
        if (completed.find(prereq) == completed.end()) return;
    }

    for (const auto& enrolled : students[sid].enrolled_courses) {
        if (courses[cc].slot == courses[enrolled].slot) return;
    }

    if (students[sid].enrolled_courses.find(cc) != students[sid].enrolled_courses.end()) {
        return;
    }

    if (courses[cc].stu.size() >= courses[cc].capacity) {
        courses[cc].waitlist.push(sid);
    } else {
        courses[cc].stu.insert(sid);
        students[sid].enrolled_courses.insert(cc);
    }
}

void dropStudent(unordered_map<std::string, Student>& students, unordered_map<std::string, Course>& courses) {
    string sid, cc;
    cin >> sid >> cc;
    if (students.find(sid) == students.end() || courses.find(cc) == courses.end()) {
        return;
    }

    courses[cc].stu.erase(sid);
    students[sid].enrolled_courses.erase(cc);

    if (!courses[cc].waitlist.empty()) {
        string next_student = courses[cc].waitlist.front();
        courses[cc].waitlist.pop();
        courses[cc].stu.insert(next_student);
        students[next_student].enrolled_courses.insert(cc);
    }
}