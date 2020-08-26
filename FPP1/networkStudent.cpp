#include <iostream>
#include "networkStudent.h"

networkStudent::networkStudent() :Student() // call to student's contstructor
{
	degreeProgram = NETWORK; // only one field to set as Student's constructor handles the rest
}

networkStudent::networkStudent(std::string studentID, std::string studentFirstName, std::string studentLastName, std::string studentEmailAddress, int studentAge, int* daysInCourse, Degree program)
	: Student(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, daysInCourse)
{
	degreeProgram = NETWORK;
}

int networkStudent::GetDegreeProgram() {
	return NETWORK;
}

void networkStudent::Print() {
	this->Student::Print(); // Call from base class
	std::cout <<"\t"<< "Degree Program: Networking" <<"\t" << std::endl;
}

networkStudent::~networkStudent() {
	Student::~Student(); // call to destructor 
}
