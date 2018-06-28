/* Class definitions for package */
/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include "Person.h"
using namespace std;

class Package{
  public:
	Package(Person, Person, double, double);
	double calculateCost();
  Person& getSender();
  Person& getRecipient();

  protected:
	Person sender;
	Person recipient;
	double weight;
	double cost;
};

#endif
