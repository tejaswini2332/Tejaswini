#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <unordered_set>

class Student {
public:
    std::string student_id;
    std::string name;
    int year;
    std::unordered_set<std::string> completed_courses;
    std::unordered_set<std::string> enrolled_courses;

    Student() = default;
};

#endif // STUDENT_H