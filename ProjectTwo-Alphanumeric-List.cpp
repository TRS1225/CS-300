
// SNHU
// CS 300
// STUDENT NAME : THOMAS SEIBERT
// This is code that will sort and print out a list of the courses in the Computer Science program in alphanumeric order
// This code is part of a larger program

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

