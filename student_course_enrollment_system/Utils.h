#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "Course.h"

bool hasCycle(const std::string& course, 
              std::unordered_map<std::string, Course>& courses, 
              std::unordered_set<std::string>& visited, 
              std::unordered_set<std::string>& recursionStack);

#endif // UTILS_H