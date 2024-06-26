// Name: Ben Douglas
// Date: 06-22-2024
// Course: CS-300
// 7-1 Project Two- Assignment

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Course {
    string courseNumber;
    string name;
    vector<string> prerequisites;
};

// Comment- I created the code to load data from the file in the data structure.

void loadDataStructure(map<string, Course>& courses, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Comment- I created the code to read the input of the courses data file.

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, name, prerequisite;
        getline(ss, courseNumber, ',');
        getline(ss, name, ',');

        Course course;
        course.courseNumber = courseNumber;
        course.name = name;

        while (getline(ss, prerequisite, ',')) {
            course.prerequisites.push_back(prerequisite);
        }

        courses[courseNumber] = course;
    }
    file.close();
}

// Comment- I developed code to sort, and print the courses in alphanumeric order.

void printCourseList(const map<string, Course>& courses) {
    for (const auto& pair : courses) {
        cout << pair.second.courseNumber << ", " << pair.second.name << endl;
    }
}

// Comment- I developed the code to print the course information.

void printCourse(const map<string, Course>& courses, const string& courseNumber) {
    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        cout << it->second.courseNumber << ", " << it->second.name << endl;
        if (!it->second.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (const auto& prereq : it->second.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Course not found." << endl;
    }
}

int main() {
    map<string, Course> courses;
    int choice;
    string filename, courseNumber;

    while (true) {

        // Comment- I created a menu option for the user.

        cout << "Welcome to the course planner." << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:

            // Comment- After the user selects option 1, then the user has to type in courses.txt to acssess the courses to be printed.

            cout << "Enter the filename to load: ";
            cin >> filename;
            loadDataStructure(courses, filename);
            break;
        case 2:
            printCourseList(courses);
            break;
        case 3:
            cout << "What course do you want to know about? ";
            cin >> courseNumber;
            transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);
            printCourse(courses, courseNumber);
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            return 0;
        default:

            // Comment- If the user picks the wrong input then it gives them an error message.

            cout << choice << " is not a valid option." << endl;
        }
    }

    return 0;
}