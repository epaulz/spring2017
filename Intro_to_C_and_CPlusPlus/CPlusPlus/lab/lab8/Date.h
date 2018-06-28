/*
 * Eric Paulz
 * epaulz@clemson.edu
 * Lab #8
 * CPSC 1021-004
 * Nick Glyder
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream> // needed to open files
#include <vector>  // needed to create vectors

using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;

	public:
		/*Default constructors*/
		Date();

		/*Overloaded constructor*/
		Date(int, int, int);

		/*Setters*/
		void setMonth(int);
		void setDay(int);
		void setYear(int);

		/*Getters*/
		int getMonth();
		int getDay();
		int getYear();

};

#endif
