
#include <iostream>
#include "softwareStudent.h"

softwareStudent::softwareStudent():Student() // call to student's contstructor
{
	degreeProgram = SOFTWARE; // only one field to set as Student's constructor handles the rest
}

softwareStudent::softwareStudent(std::string studentID, std::string studentFirstName, std::string studentLastName, std::string studentEmailAddress, int studentAge, int *daysInCourse, Degree program)
	:Student(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, daysInCourse)
{
	degreeProgram = SOFTWARE;
}

int softwareStudent::GetDegreeProgram() {
	return SOFTWARE;
	
}

void softwareStudent::Print() {
	this->Student::Print(); // Call from base class
	std::cout <<"\t" << "Degree Program: Software" << "\t" << std::endl;
}

softwareStudent::~softwareStudent() {
	Student::~Student(); // call to destructor 
}
