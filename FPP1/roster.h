#pragma once


#include <iostream>
#include "student.h"
#include "softwareStudent.h"

class Roster {
private:

	int lastIndex; // Last data row in Roster
	int maxSize; // The size of the Roster
	Student** classRosterArray; // Array of pointers :D 

public:
	Roster(); // Default Contstructor 
	Roster(int size); // Full Constructor

	Student* getStudents(int position); // retrive data from data row using position
	void parseString(std::string row); // parses the string
	void add(std::string studentID, std::string firstName, std::string lastName, std::string eamilAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program); // Insert's data into repository
	void remove(std::string studentID); // Removes students from the roster by student ID.
	void printAll(); // Prints a complete tab-separated list of student data using accessor functions
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int program);
	void remove(int studentID);
	~Roster(); //Destructor! 
};

