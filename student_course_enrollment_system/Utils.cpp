#include "Utils.h"

bool hasCycle(const std::string& course, 
              std::unordered_map<std::string, Course>& courses, 
              std::unordered_set<std::string>& visited, 
              std::unordered_set<std::string>& recursionStack) {
    if (recursionStack.count(course)) return true;
    if (visited.count(course)) return false;

    visited.insert(course);
    recursionStack.insert(course);

    for (const auto& prereq : courses[course].prerequisites) {
        if (hasCycle(prereq, courses, visited, recursionStack)) {
            return true;
        }
    }

    recursionStack.erase(course);
    return false;
}