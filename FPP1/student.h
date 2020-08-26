#pragma once
#include <iostream>
#include "degree.h"



class Student { // Student base Class

public:
	 
	Student(); //Constructor empty
    Student(std::string studentID, std::string studentFirstName, std::string studentLastName, std::string studentEmailAddress, int studentAge, int *daysInCourse); //full contstuctor
	~Student(); //Destructor

	//Mutators///////////////////
	void SetStudentID(std::string studentID);
	void SetFirstName(std::string studentLastName);
	void SetLastName(std::string studentLastName);
	void SetEmailAddress(std::string studentEmailAddress);
	void SetStudentAge(int studentAge);
	void SetDaysRemaining(int daysInCourse[]);
	void SetDegreeName(Degree type);

	//// Accessors//////////////////
	std::string GetStudentID() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetEmailAddress() const;
	int GetStudentAge() const;
	int* GetDaysRemaining();
	virtual int GetDegreeProgram() = 0;

	virtual void Print() = 0;

	const static int daysRemainingArraysize = 3; 

protected:  //Visable by derrived classes 

	std::string studentID;
	std::string studentFirstName;
	std::string studentLastName;
	std::string studentEmailAddress;
	int studentAge;
	int daysInCourse[daysRemainingArraysize];
	Degree degreeProgram;
	
};

