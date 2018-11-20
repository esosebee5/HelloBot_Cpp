// HelloBot_Cpp.cpp : Defines the entry point for the console application.
//

#include "time.h"
#include "stdafx.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream> 
#include <sstream> 
using namespace std;

/* This prints a line to show the beginning of the app */
void startApp();
/* This prints a line to show the end of the app */
void endApp();
/* Returns a tm structure containing current date and time information */
tm * getCurrentDateTime();
/* Runs a subprogram based on input from the user */
bool chooseProgram(string in);
/* Launches a subprogram that writes out the current time
	in hours, minutes, and seconds */
void clockApp();
/* Calculates age in years based on input birth date */
void calculateAge();

//+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Month Structure 
// - int number
// - int days
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct Month
{
	int number;
	int days;
};
/* Takes in a string from the user and returns the int equivalent of that month */
Month getBirthMonth();
/* Creates and returns a month struct based on the passed data */
Month getMonth(string in);
/* Returns a valid number for day of the month based on the number of days being passed in */
int getBirthDay(int numberOfDays);
/* Returns an integer year based on the input string */
int getBirthYear(int currentYear);
/* Shared method to handle string -> int conversion */
void convertStringToIntIfValid(std::string &inputString, int &retVal);


//+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Main Method 
// - Loops through the main menu, executing the
//   subprograms as requested until 'end' is entered.
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+
int main()
{	
	bool state = true;
	string name;
	cout << "Welcome to the C++ HelloBot Project!" << endl 
		 << endl << "Enter your name: ";
	cin >> name;
	cout << "Hello, " << name << endl << endl;

	do
	{
		string command;
		cout << "Enter '1' for Clock, '2' to Calculate Age, or "
			 << endl << "enter 'end' to terminate : ";
		cin >> command;
		cout << endl;
		state = chooseProgram(command);
	} while (state);

	return 0;
}

bool chooseProgram(string in) 
{
	if (in._Equal("1")) 
	{
		clockApp();
		return true;
	}
	else if (in._Equal("2"))
	{
		calculateAge();
		return true;
	}
	else if (in._Equal("end"))
	{
		cout << "User has ended process.";
		return false;
	}
}

//+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Clock
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+

void clockApp()
{
	startApp();
	tm *currentDT = getCurrentDateTime();
	cout << "The current time is " << currentDT->tm_hour << ":"
		 << currentDT->tm_min << ":" << currentDT->tm_sec << endl;
	endApp();
}

//+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Calculate Age
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+

void calculateAge()
{
	startApp();

	// get current d/t below:
	tm *ltm = getCurrentDateTime();
	int currentYear = 1900 + ltm->tm_year;
	int currentMonth = 1 + ltm->tm_mon;
	int currentDay = ltm->tm_mday;

	// get birth month
	Month birthMonth;
	birthMonth = getBirthMonth();
	
	// get birth day
	int birthDay;
	birthDay = getBirthDay(birthMonth.days);

	// get birth year
	int birthYear;
	birthYear = getBirthYear(currentYear);

	// Perform calculation
	bool alreadyHadBirthday = 0;
	int age = 0;
	int monthsTill = 0;
	int daysTill = 0;
	if (currentMonth > birthMonth.number || (currentMonth == birthMonth.number && currentDay >= birthDay))
	{
		alreadyHadBirthday = 1;
		age = currentYear - birthYear;
	}
	else 
	{
		age = currentYear - birthYear - 1;
	}
	////
	//// logging
	//cout << "Had birthday: " << alreadyHadBirthday << endl;
	//cout << "age: " << age << endl;
	////

	cout << "You are " << age << " years old." << endl;
	
	endApp();
}

Month getBirthMonth()
{
	string monthInput;
	string s;
	Month birthMonth = { 0,0 };

	while (birthMonth.days == 0)
	{
		cout << "Enter your birth month: ";
		cin >> monthInput;
		birthMonth = getMonth(monthInput);
	}
	
	//// FOR LOGGING 
	//cout << "month number: " << birthMonth.number << endl;
	//cout << "days in month: " << birthMonth.days << endl;
	//// END LOGGING

	return birthMonth;
}

Month getMonth(string in)
{
	Month month;
	transform(in.begin(), in.end(), in.begin(), ::tolower);

	if (in._Equal("jan") || in._Equal("january"))
	{
		month = { 1, 31 };
	}
	else if (in._Equal("feb") || in._Equal("february"))
	{
		month = { 2, 28 };
	}
	else if (in._Equal("mar") || in._Equal("march"))
	{
		month = { 3, 31 };
	}
	else if (in._Equal("apr") || in._Equal("april"))
	{
		month = { 4, 30 };
	}
	else if (in._Equal("may"))
	{
		month = { 5, 31 };
	}
	else if (in._Equal("jun") || in._Equal("june"))
	{
		month = { 6, 30 };
	}
	else if (in._Equal("jul") || in._Equal("july"))
	{
		month = { 7, 31 };
	}
	else if (in._Equal("aug") || in._Equal("august"))
	{
		month = { 8, 31 };
	}
	else if (in._Equal("sep") || in._Equal("september"))
	{
		month = { 9, 30 };
	}
	else if (in._Equal("oct") || in._Equal("october"))
	{
		month = { 10, 31 };
	}
	else if (in._Equal("nov") || in._Equal("november"))
	{
		month = { 11, 30 };
	}
	else if (in._Equal("dec") || in._Equal("december"))
	{
		month = { 12, 31 };
	}
	else
	{
		month = { 0, 0 };
	}

	return month;
}

int getBirthDay(int numberOfDays)
{
	int day = 0;

	while (day <= 0 || day > numberOfDays)
	{
		cout << "Enter the day of the month: ";

		string inputString;
		cin >> inputString;

		convertStringToIntIfValid(inputString, day);

	}
	////
	//// logging
	//cout << "day: " << day << endl;
	////

	return day;
}

int getBirthYear(int currentYear)
{
	int year = 0;

	while (year <= 0 || year > currentYear)
	{
		cout << "Enter your birth year: ";

		string inputString;
		cin >> inputString;

		convertStringToIntIfValid(inputString, year);

	}
	////
	//// logging
	//cout << "year: " << year << endl;
	////

	return year;
}

void convertStringToIntIfValid(std::string &inputString, int &retVal)
{
	string validNums = "0123456789";
	int validCount = 0;

	for (int i = 0; i < inputString.size(); i++)
	{
		std::size_t found = validNums.find(inputString[i]);
		if (found != std::string::npos)
		{
			validCount++;
		}
	}

	if (validCount == inputString.length())
	{
		istringstream converter(inputString);
		converter >> retVal;
	}
}


//+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Shared Methods
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+

tm * getCurrentDateTime()
{
	time_t now = time(0);
	tm *ltm = new tm;
	localtime_s(ltm, &now);
	return ltm;
}

void startApp()
{
	cout << "--------------------------------" << endl;
}

void endApp()
{
	cout << "--------------------------------" << endl << endl;
}
