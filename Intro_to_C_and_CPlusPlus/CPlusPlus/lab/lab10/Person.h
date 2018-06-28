/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person{
  private:
    string name;
    string address;
    string city;
    string state;
    int zip;

  public:
    Person(string, string, string, string, int);
    Person();
    void setName(string);
    void setAddress(string);
    void setState(string);
    void setCity(string);
    void setZip(int);

    void printSenderInfo();
    void printRecipientInfo();

};

#endif
