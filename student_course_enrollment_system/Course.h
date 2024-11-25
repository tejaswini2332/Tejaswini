#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <unordered_set>
#include <queue>

class Course {
public:
    std::string course_code;
    std::string course_name;
    int credits;
    int capacity;
    std::unordered_set<std::string> prerequisites;
    std::unordered_set<std::string> stu;
    std::queue<std::string> waitlist;
    char slot;

    Course() = default;
};

#endif // COURSE_H