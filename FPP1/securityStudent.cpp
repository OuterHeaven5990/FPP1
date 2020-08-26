#include <iostream>
#include "securityStudent.h"

securityStudent::securityStudent() :Student() // call to student's contstructor
{
	degreeProgram = NETWORK; // only one field to set as Student's constructor handles the rest
}

securityStudent::securityStudent(std::string studentID, std::string studentFirstName, std::string studentLastName, std::string studentEmailAddress, int studentAge, int* daysInCourse, Degree program)
	: Student(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, daysInCourse)
{
	degreeProgram = SECURITY;
}

int securityStudent::GetDegreeProgram() {
	return SECURITY;
}

void securityStudent::Print() {
	this->Student::Print(); // Call from base class
	std::cout <<"\t" << "Degree Program: Security" <<"\t" << std::endl;
}

securityStudent::~securityStudent() {
	Student::~Student(); // call to destructor 
}
