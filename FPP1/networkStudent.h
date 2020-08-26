#pragma once
#include "student.h"

class networkStudent : public Student // Derrived class from Student
{
public:

	networkStudent(); // Empty Constructor
	networkStudent(std::string studentID, std::string firstName, std::string lastName, std::string Semail, int Studentage, int* daysInCourse, Degree program); // Full constructor 

	// These will override the base class Student's virtual methods
	int GetDegreeProgram();
	void Print();

	~networkStudent(); // Destructor

};

