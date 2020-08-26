#pragma once
#include "student.h"

class softwareStudent : public Student // Derrived class from Student
{
public:

	softwareStudent(); // Empty Constructor
	softwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string Semail, int Studentage, int *daysInCourse, Degree program); // Full constructor 

	// These will override the base class Student's virtual methods
	int GetDegreeProgram();
	void Print();

	~softwareStudent(); // Destructor

};

