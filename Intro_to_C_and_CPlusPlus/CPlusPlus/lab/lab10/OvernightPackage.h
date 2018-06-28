/* Class definitions for overnight package */

/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"
#include <string>
using namespace std;

class OvernightPackage:public Package{
    public:
        OvernightPackage(Person, Person, double, double, double, double);
        double calculateCost();

    private:
        double additionalFee;
        double flatFee;
};
#endif
