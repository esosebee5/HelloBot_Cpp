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
	Month birthMonth;
	birthMonth = getBirthMonth();
	int birthYear;
	int birthDay;
	
	cout << "Enter your birth day (of the month): ";
	cin >> birthDay;
	cout << "Enter your birth year: ";
	cin >> birthYear;

	cout << "you entered: " << birthMonth.number << birthDay << birthYear;



	// get current d/t below:
	tm *ltm = getCurrentDateTime();

	// example of various components of tm structure:
	cout << "Year: " << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;

	int currentYear = 1900 + ltm->tm_year;
	int currentMonth = 1 + ltm->tm_mon;
	int currentDay = ltm->tm_mday;
	cout << currentYear << ", " << currentMonth << ", "
		<< currentDay << "." << endl;
}

Month getBirthMonth()
{
	string monthInput;
	cout << "Enter your birth month: ";
	cin >> monthInput;
	Month birthMonth = getMonth(monthInput);

	// FOR LOGGING 
	cout << "month number: " << birthMonth.number << endl;
	cout << "days in month: " << birthMonth.days << endl;
	// END LOGGING

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
		month = { 1, 31 };
	}
	else if (in._Equal("apr") || in._Equal("april"))
	{
		month = { 1, 30 };
	}
	else if (in._Equal("may"))
	{
		month = { 1, 31 };
	}
	else if (in._Equal("jun") || in._Equal("june"))
	{
		month = { 1, 30 };
	}
	else if (in._Equal("jul") || in._Equal("july"))
	{
		month = { 1, 31 };
	}
	else if (in._Equal("aug") || in._Equal("august"))
	{
		month = { 1, 31 };
	}
	else if (in._Equal("sep") || in._Equal("september"))
	{
		month = { 1, 30 };
	}
	else if (in._Equal("oct") || in._Equal("october"))
	{
		month = { 1, 31 };
	}
	else if (in._Equal("nov") || in._Equal("november"))
	{
		month = { 1, 30 };
	}
	else if (in._Equal("dec") || in._Equal("december"))
	{
		month = { 1, 31 };
	}

	return month;
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
