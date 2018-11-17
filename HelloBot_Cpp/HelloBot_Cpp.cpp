// HelloBot_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <sstream> 
using namespace std;

int main()
{
	// string type
	string s = "helloWorld";

	// character type
	char str = 'h';

	// character array type?
	char* k = "jj";
	char* all = "jjh";

	// only prints character array
	printf(all);
	printf("\n");
	printf(s.c_str());

	char atOne = k[1];
	// new output method

	string name;
	cout << "enter name: ";
	cin >> name;
	cout << name << endl;

    return 0;
}

