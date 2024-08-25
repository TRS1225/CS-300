
// SNHU
// CS 300
// MOD 7: PROJECT TWO
// STUDENT NAME : THOMAS SEIBERT
// This program is a course planner made for ABCU Computer Science department advisors.

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// Create struct Course
// Vector to store pre-reqs
struct Course {
	string number;
	string title;
	vector<string> prerequisites;
};

// Use unordered map as a hash table
unordered_map<string, Course> courses;

// Function to read data and load data into hash table
void loadDataIntoHashTable(string fileName) {
	//declare variable
	string line;
	Course course;

	//if statement to check error 
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	// loop to get lines in file
	while (getline(file, line)) {
		istringstream iss(line);
		vector<string> parts;
		string part;
		while (getline(iss, part, ' ')) {
			parts.push_back(part);
		}

		// validation
		if (parts.size() < 2) {
			cout << "Invalid file format" << endl;
			continue;
		}

		// declare course parts
		course.number = parts[0];
		course.title = parts[1];

		if (parts.size() > 2) {
			for (int i = 2; i < parts.size(); i++) {
				course.prerequisites.push_back(parts[i]);
			}
		}

		// declare course number
		courses[course.number] = course;
	}

	file.close();
}

// Function to search for course in hash table and print course info
void searchCourse(string courseNumber) {
	//find courses
	if (courses.find(courseNumber) != courses.end()) {
		Course course = courses[courseNumber];
		cout << "Course Number: " << course.number << endl;
		cout << "Course Title: " << course.title << endl;

		// list pre-reqs
		if (!course.prerequisites.empty()) {
			cout << "Prerequisites: " << endl;
			for (string prerequisite : course.prerequisites) {
				cout << prerequisite << endl;
			}
		}
		else {
			cout << "No prerequisites" << endl;
		}
	}
	else {
		cout << "Course not found" << endl;
	}
}

//Function to validate file format
void validateFileFormat(string fileName) {
	// declare variables
	string line;

	//if statement to validate
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	//loop to validate
	while (getline(file, line)) {
		istringstream iss(line);
		vector<string> parts;
		string part;
		while (getline(iss, part, ' ')) {
			parts.push_back(part);
		}

		// if parts size < 2 invalid
		if (parts.size() < 2) {
			cout << "Invalid file format" << endl;
			continue;
		}

		// loop to validate prereq
		for (int i = 2; i < parts.size(); i++) {
			if (courses.find(parts[i]) == courses.end()) {
				cout << "Invalid prerequisite: " << parts[i] << endl;
			}
		}
	}
	file.close();
}

// Function to read file and parse data into hash table
unordered_map<string, string> load_data(Course) {
	unordered_map<string, string> courses;
	return courses;
}

// Function to print courses in an ordered manner
void print_ordered_courses(unordered_map<string, string>& Course) {
}

// Function to print details about a course or courses
void print_course_details(unordered_map<string, string>& Course, string courses) {
}

// Main function containing menu
int main() {
	// declare variables
	Course mycourses;
	unordered_map<string, string> hash_table;
	int user_input;
	string course_name;
	vector<string> courses;
	string courseInformation[] = { "CSCI100,Introduction to Computer Science", 
		"CSCI101,Introduction to Programming in C++,CSCI100", 
		"CSCI200,Data Structures,CSCI101",
		"MATH201,Discrete Mathematics",
		"CSCI300,Introduction to Algorithms,CSCI200,MATH201",
		"CSCI301,Advanced Programming in C++,CSCI101",
		"CSCI350,Operating Systems,CSCI300", 
		"CSCI400,Large Software Development,CSCI301,CSCI350", };

	// loop to display menu
	while (true) {
		cout << "1. Load data" << endl;
		cout << "2. Print ordered list of courses" << endl;
		cout << "3. Print course details" << endl;
		cout << "9. Exit" << endl;

		// get user input
		cin >> user_input;

		// option 1
		if (user_input == 1) {
			hash_table = load_data(mycourses);
		}

		// option 2
		else if (user_input == 2) {
			if (!hash_table.empty()) {
				print_ordered_courses(hash_table);
			}
			else {
				cout << "Please load the data first." << endl;
			}
		}

		// option 3
		else if (user_input == 3) {
			if (!courses.empty()) {
				cout << "Enter course name: ";
				cin >> course_name;
				print_course_details(hash_table, course_name);
			}
			else {
				cout << "Please load the data first." << endl;
			}
		}

		// exit option (9)
		else if (user_input == 9) {
			break;
		}
		else {
			cout << "Invalid option. Please try again." << endl;
		}
	}

	// loop to sort each line in course information
	for (string line : courseInformation) {
		// Split line by commas
		stringstream ss(line);
		string courseNumber;
		getline(ss, courseNumber, ',');

		// Add course number to 'courses' list
		courses.push_back(courseNumber);
	}

	// sort 'courses' list in alphanumeric order
	sort(courses.begin(), courses.end());

	// loop to sort each course in the 'courses' list:
	for (string course : courses) {
		// print the course
		cout << course << endl;
	}

	return 0;
}

