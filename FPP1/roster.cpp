
#include <iostream>
#include<string>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

using namespace std;

Roster::Roster()  // Empty Constructor 
{
	this->maxSize = 0;
	this->lastIndex = -1; // creates an empty index as 0 is a valid array size
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
	this->maxSize = maxSize;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[maxSize];
}




void Roster::parseString(string row) // will parse string then call Add function at the end
{
	if (lastIndex < maxSize) {
		lastIndex++;

		//Find student ID
		int rightSide = row.find(","); 
		string studentID = row.substr(0, rightSide);

		//find First name

		int leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string studentFirstName = row.substr(leftSide, rightSide - leftSide);

		//find Last name

		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string studentLastName = row.substr(leftSide, rightSide - leftSide);

		//find email

		 leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string emailAddress = row.substr(leftSide, rightSide - leftSide);

		//find age

		 leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int age = std::stoi(row.substr(leftSide, rightSide - leftSide));

		// find course 1

		 leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int daysInCourse1 = std::stoi(row.substr(leftSide, rightSide - leftSide));

		//find course 2

		 leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int daysInCourse2 = std::stoi(row.substr(leftSide, rightSide - leftSide));

		//find course 3


		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int daysInCourse3 = std::stoi(row.substr(leftSide, rightSide - leftSide));

		// find degree program 
		Degree degreeProgram;
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string tempProgram = row.substr(leftSide, rightSide - leftSide);
		if (tempProgram == "SOFTWARE") { degreeProgram = SOFTWARE; }
		if (tempProgram == "SECURITY") { degreeProgram = SECURITY; }
		if (tempProgram == "NETWORK") { degreeProgram = NETWORK; }


		
		
		add(studentID, studentFirstName, studentLastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram); // Function call to add the data
		

		
	}

}

// Function to add the data
void Roster::add(string studentID, string firstName, string lastName, string emaillAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int course[Student::daysRemainingArraysize];
	course[0] = daysInCourse1;
	course[1] = daysInCourse2;
	course[2] = daysInCourse3;

	if (degreeProgram == SOFTWARE) 

	{
		classRosterArray[lastIndex] = new softwareStudent(studentID, firstName, lastName, emaillAddress, age, course, degreeProgram);
	}
	
	if (degreeProgram == NETWORK)

	{
		classRosterArray[lastIndex] = new networkStudent(studentID, firstName, lastName, emaillAddress, age, course, degreeProgram);
	}

	if (degreeProgram == SECURITY)

	{
		classRosterArray[lastIndex] = new securityStudent(studentID, firstName, lastName, emaillAddress, age, course, degreeProgram);
	}
	
}

// Function to remove Student

void Roster::remove(string studentID) 
{
	bool flag = false; 

	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID) //Locate book by itterating through student roster and calling base class accessor
		{
			delete this->classRosterArray[i];
			
			//Close the gap in the array be assighing a pointer to this location; 
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--; // Roster is now 1 element less; 

			cout << "Removing student " << studentID << endl; 
			flag = true;
			break;
		}
	}

	if (flag == false)
	{
		cout << "Student not found" << endl;
	}
}

Student * Roster::getStudents(int index)
{
	return classRosterArray[index];
}

void Roster::printAverageDaysInCourse(string studentID)
{
	

	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			int* avg = classRosterArray[i]->GetDaysRemaining();
			cout <<"Average days remaining for " << classRosterArray[i]->GetFirstName() << " is " << (avg[0] + avg[1] + avg[2]) / 3 << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < 5; i++)
	{
		bool isSpace = false;
		bool isPeriod = false;
		bool isAT = false;

		string studentEmail = "";
		studentEmail = classRosterArray[i]->GetEmailAddress();
		
		for (char& checker : studentEmail)
		{
			if (checker == '@') { isAT = true; }
			if (checker == ' ') { isSpace = true; }
			if (checker == '.') { isPeriod = true; }
		}

		if (isAT == false || isPeriod == false || isSpace == true)
		{
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
}

void Roster::printByDegreeProgram(int program)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetDegreeProgram() == program)
		{
			this->classRosterArray[i]->Print();
		}
	}
}

void Roster::printAll()
{

	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->Print();
}



Roster::~Roster() // Destorys all roster entries
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}


void main()
{
	int numStudents = 5;

	const string studentData[] =
	{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Scott,Weekley,sweekl7@wgu.edu,29,40,50,60,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudents);
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseString(studentData[i]);
	}
	
	//print out Student Info 
	cout << "Scripting and Programming - Applications C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID# 001026151" << endl;
	cout << "Scott Weekley" << endl;
	cout << endl;

	classRoster->printAll(); cout << endl;

	cout << "Invalid email addresses: " << endl; cout << endl;

	classRoster->printInvalidEmails(); cout << endl;

	cout << "Average days remaining for students: " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->printAverageDaysInCourse(classRoster->getStudents(i)->GetStudentID());
	}

	cout << endl;

	cout << "Printing student by type: " << endl; cout << endl;
	classRoster->printByDegreeProgram(SOFTWARE); cout << endl;

	classRoster->remove("A3"); cout << endl;
	classRoster->remove("A3"); cout << endl;
	classRoster->~Roster();
}
