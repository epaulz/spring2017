/* Class definitions for a three day package */
/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/

#ifndef THREEDAY_H
#define THREEDAY_H

#include "Package.h"
#include <string>
using namespace std;

class ThreeDay:public Package{
   public:
	 ThreeDay(Person, Person, double, double, double);
	 double calculateCost();

   private:
	 double additionalFee;
};
#endif
