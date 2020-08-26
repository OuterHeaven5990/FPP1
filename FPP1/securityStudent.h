#pragma once
#include "student.h"

class securityStudent : public Student // Derrived class from Student
{
public:

	securityStudent(); // Empty Constructor
	securityStudent(std::string studentID, std::string firstName, std::string lastName, std::string Semail, int Studentage, int* daysInCourse, Degree program); // Full constructor 

	// These will override the base class Student's virtual methods
	int GetDegreeProgram();
	void Print();

	~securityStudent(); // Destructor

};

