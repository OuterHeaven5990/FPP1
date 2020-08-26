
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"


Student::Student() { // Default Constructor 

	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < daysRemainingArraysize; i++) this->daysInCourse[i] = 0;

}

Student::Student(std::string studentID, std::string studentFirstName, std::string studentLastName, std::string studentEmailAddress, int studentAge, int *daysIncourse)  // Full constructor

{
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmailAddress = studentEmailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < daysRemainingArraysize; i++)
	{
		this->daysInCourse[i] = daysIncourse[i];
	}
}

//Mutators///////////////////

void Student::SetStudentID(std::string studentID) {
	this->studentID = studentID;
	
}

void Student::SetFirstName(std::string studentFirstName) {
	this->studentFirstName = studentFirstName;
}

void Student::SetLastName(std::string studentLastName) {
	this->studentLastName = studentLastName;

}

void Student::SetEmailAddress(std::string studentEmailAddress) {
	this->studentEmailAddress = studentEmailAddress;
	
}

void Student::SetStudentAge(int studentAge) {
	this->studentAge = studentAge;
	
}

void Student::SetDaysRemaining(int daysInCourse[]) {

	for (int i = 0; i < daysRemainingArraysize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}
void Student::SetDegreeName( Degree degreeProgram){
	this->degreeProgram = degreeProgram;
}

//// Accessors//////////////////

std::string Student::GetStudentID() const {
	return studentID;
}

std::string Student::GetFirstName() const {
	return studentFirstName;
}
std::string  Student::GetLastName() const {
	return studentLastName;
}
std::string Student::GetEmailAddress() const {
	return studentEmailAddress;
}
int Student::GetStudentAge() const {
	return studentAge;
}

int* Student::GetDaysRemaining()  {
	return daysInCourse;
}


void Student::Print() {
	std::cout << GetStudentID();
	std::cout << "\t" << "First Name: " << GetFirstName() << "\t";
	std::cout << "\t" << "Last Name: " << GetLastName() << "\t";
	std::cout << "\t" << "Age: " << GetStudentAge() << "\t";
	std::cout << "\t" << "daysinCourse: " << "{" << daysInCourse[0] << ","<< daysInCourse[1] << "," << daysInCourse[2] << "}";


}

Student::~Student() { //Destructor 
	
}