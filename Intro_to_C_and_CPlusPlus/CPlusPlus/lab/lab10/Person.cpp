/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/

#include "Person.h"
#include <iostream>
using namespace std;

/*Use initialization list to initialize the two following constructors */
Person::Person(string name, string address, string city, string state, int zip) :
  name(name), address(address), city(city), state(state), zip(zip){}

Person::Person() : name("Donald Duck"), address("123 Disney Ave"),
  city("Walt"), state("Disney"), zip(54321){}

/*Setters*/
void Person::setName(string name){
    this->name = name;
}
void Person::setAddress(string address){
    this->address = address;
}
void Person::setState(string state){
    this->state = state;
}
void Person::setCity(string city){
    this->city = city;
}
void Person::setZip(int zip){
    this->zip = zip;
}

/*The next two functions are used to print the Sender and Recipient's
 *mailing information*/
void Person::printSenderInfo(){
  cout << "SENDER ADDRESS:" << endl;
  cout << name << endl << address << endl;
  cout << city << ", " << state << " " << zip << endl << endl;
}

void Person::printRecipientInfo(){
  cout << "RECIPIENT ADDRESS:" << endl;
  cout << name << endl << address << endl;
  cout << city << ", " << state << " " << zip << endl << endl;
}
