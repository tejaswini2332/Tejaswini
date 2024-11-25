# Student Course Management System

## Description

The **Student Course Management System** is a C++ program designed to manage student enrollments, courses, prerequisites, waitlists, and student course drops efficiently. The system ensures smooth enrollment and course management by considering prerequisites, capacity checks, and cyclic prerequisite detection.

## Features

### 1. **Add Students**
   - The system allows you to add students to the system by entering their details (e.g., name, student ID, etc.). 
   - Each student is assigned a unique ID and can enroll in multiple courses throughout their academic journey. 
   - This feature ensures that student records are tracked and managed properly within the system.

   **Example Workflow**:
   - The administrator can add a student by providing the student’s name, ID, and other relevant details (e.g., email, program).
   - Once added, students can be enrolled in courses, tracked for progress, and managed within the system.

---

### 2. **Add Courses**
   - You can add new courses to the system, specifying key details such as the course name, course ID, instructor, and course prerequisites (if any).
   - Each course can have a specified **capacity**, which is the maximum number of students allowed to enroll. 
   - The system maintains the course list and manages student enrollments against these capacities.

   **Example Workflow**:
   - The administrator adds a new course by providing details like the course code (e.g., CS101), name (e.g., Introduction to Programming), and prerequisites (e.g., Basic Math).
   - The system keeps track of the course capacity and prerequisites for the course.
   - The course is added to the available list of courses, and students can then be enrolled in it.

---

### 3. **Enroll Students**
   - The system allows students to enroll in courses, but enrollment is subject to **course capacity** and **prerequisite requirements**.
   - If the course is full, students will be placed on a **waitlist**, ensuring that they are automatically enrolled when spots become available.
   - **Prerequisite checks** are performed before enrollment: a student can only enroll in a course if they have successfully completed the prerequisite courses.

   **Example Workflow**:
   - A student tries to enroll in a course (e.g., CS101).
   - The system checks if the student has completed the required prerequisite courses (e.g., Math 101).
   - If the student meets the prerequisites and if the course has available spots, they are successfully enrolled.
   - If the course is full, the student is placed on the waitlist, and when a student drops the course, the next student in the waitlist is enrolled automatically.

---

### 4. **Waitlist Management**
   - When a course reaches its maximum capacity, students who attempt to enroll are placed on a **waitlist**.
   - As soon as a student drops the course, the system automatically enrolls the next student in the waitlist, respecting the **first-come, first-served** principle.
   - The waitlist ensures that courses are filled optimally and no available spots go unfilled.

   **Example Workflow**:
   - A student tries to enroll in a course that is already full. The student is added to the waitlist.
   - When a student who is enrolled in that course drops it, the first student in the waitlist is automatically enrolled in the course.
   - The system notifies students of successful enrollment or updates about their waitlist position.

---

### 5. **Prerequisite Checks**
   - Before enrolling in a course, the system ensures that students meet all the **prerequisite requirements** for the course.
   - If a course requires completion of another course (e.g., CS101 requires Math101), the system will only allow enrollment if the student has already completed the prerequisite courses.
   - This feature maintains the **academic integrity** of the system, ensuring that students follow the correct learning progression.

   **Example Workflow**:
   - A student wishes to enroll in a course (e.g., CS102).
   - The system checks whether the student has completed the required prerequisite course (e.g., CS101).
   - If the student has not completed the prerequisite, the system prevents enrollment and notifies the student.

---

### 6. **Cyclic Prerequisite Detection**
   - The system detects and prevents the creation of **cyclic prerequisites**, where courses depend on each other in a circular fashion (e.g., Course A requires Course B, and Course B requires Course A).
   - Cyclic prerequisites violate the dependency hierarchy and prevent students from being able to take courses in a logical order.
   - The system ensures that the prerequisite structure remains acyclic, making the course flow logical and achievable for students.

   **Example Workflow**:
   - A new course (e.g., CS101) is added, and prerequisites are specified.
   - If Course A depends on Course B, and Course B also depends on Course A, the system detects this cycle and rejects the course addition, alerting the administrator to the cyclic dependency.
   - This feature prevents academic deadlocks and ensures students can complete courses in a valid order.

---

### 7. **Drop Students from Courses**
   - Students can drop courses they are currently enrolled in, either voluntarily or due to other reasons (e.g., schedule conflicts, academic performance).
   - When a student drops a course, the system processes the **waitlist**, and the next student on the list is automatically enrolled if there is room.
   - The system ensures that the course enrollment is up-to-date, and students who drop courses are properly removed from both the course roster and waitlist.

   **Example Workflow**:
   - A student decides to drop a course (e.g., CS101) due to personal reasons.
   - The system automatically removes the student from the course and updates the waitlist.
   - If there are students waiting to be enrolled, the next student in the waitlist is enrolled, and the student is notified.

---

### 8. **User Interaction via Command-Line Interface (CLI)**
   - The system operates via a command-line interface (CLI), where users (e.g., administrators, students) can perform various operations by entering simple commands.
   - This allows efficient, text-based management of students, courses, enrollments, waitlists, and prerequisites.

   **Example Workflow**:
   - The user is prompted with a menu of available actions (e.g., "1. Add Student", "2. Add Course", "3. Enroll Student", etc.).
   - The user enters a choice, followed by relevant input (e.g., student details, course name).
   - The system responds with feedback, whether the action was successful or if there were any errors (e.g., prerequisites not met, course full, etc.).

---

### 9. **Extensible Architecture**
   - The system’s architecture is modular and extensible, making it easy to add new features in the future (e.g., support for more complex course prerequisites, student grading, or advanced waitlist handling).
   - Each component (students, courses, prerequisites, waitlist) is managed independently, enabling easy updates and enhancements.

   **Example Workflow**:
   - New features, such as support for course scheduling or the ability to assign grades to students, can be added by extending the existing classes without affecting the rest of the system.
   - This modular design promotes code maintainability and future feature development.

---

## Build and Run

### Requirements

- A C++ compiler (GCC/Clang)
- **make** utility (optional but recommended for building the project easily)

### Build Instructions

1. Clone the repository:
    ```bash
    git clone https://github.com/your-repo/student-course-management.git
    ```

2. Navigate to the project directory:
    ```bash
    cd student-course-management
    ```

3. Compile the project using `make` (if the `Makefile` is included):
    ```bash
    make
    ```

   Alternatively, compile manually:
    ```bash
    g++ -o student_course_management main.cpp
    ```

4. Run the program:
    ```bash
    ./student_course_management
    ```

---

## Usage

Once the system is running, you will be presented with a menu where you can:
- Add students and courses
- Enroll students in courses
- Drop students from courses
- View the waitlist for full courses
- Check for cyclic prerequisites
- More...

Follow the on-screen prompts to perform actions, and the system will guide you through each operation.

---
