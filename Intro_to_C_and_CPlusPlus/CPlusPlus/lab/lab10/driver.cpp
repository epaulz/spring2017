/* Driver for lab  files */
/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/
#include "Package.h"
#include "ThreeDay.h"
#include "OvernightPackage.h"
#include "Person.h"
using namespace std;

#include <iostream>
#include <iomanip>

/*You will need to write the implementation for the following functions.  */

void getSenderInfo(Person &);
void getRecipientInfo(Person &);
void calculateAndPrint(Package &, ThreeDay&, OvernightPackage&);
void getPackageInfo(double&, double&, double&, double&, double&);


int main(){
   double w, cost, fee1, fee2, flat;

   Person s;
   Person r;
   getSenderInfo(s);
   getRecipientInfo(r);
   getPackageInfo(w, cost, fee1, fee2, flat);

   // create the package objects
   Package p1(s, r, w, cost);
   ThreeDay p2(s, r, w, cost, fee1);
   OvernightPackage p3(s, r, w, cost, fee2, flat);

   calculateAndPrint(p1, p2, p3);

   return 0;
}

/*This function is used to request and receive information from the user
 *The information received from this function will be used to instantiate the
 *instances of Package, ThreeDay, and OvernightPackage in the main.  See
 *the sample output in the lab specification document for an example.*/

void getPackageInfo(double& w, double& cost, double& fee1, double& fee2,
                    double& flat){
  cout << "Enter the weight, in oz, of the package: ";
  cin >> w;
  cout << "Enter the cost per oz, in dollars, of the package: ";
  cin >> cost;
  cout << "Enter the additional fee per ounce of the 3-day package: ";
  cin >> fee1;
  cout << "Enter the additional fee per ounce of the overnight package: ";
  cin >> fee2;
  cout << "Enter the flat fee for the overnight package: ";
  cin >> flat;
}

/*This function is used to request and receive information from the user.
 *The information is used to set the values of a person that will be
 *passed to the instances of Package, ThreeDay, and OverrnightPackage.
 *It represents the "sender" of the Package class.*/

void getSenderInfo(Person& sender){
  string temp;
  int zip_code;

  cout << "Enter the sender's name: ";
  getline(cin, temp);
  sender.setName(temp);

  cout << "Enter the sender's street address: ";
  getline(cin, temp);
  sender.setAddress(temp);

  cout << "Enter the sender's city: ";
  getline(cin, temp);
  sender.setCity(temp);

  cout << "Enter the sender's state: ";
  getline(cin, temp);
  sender.setState(temp);

  cout << "Enter the sender's ZIP code: ";
  cin >> zip_code;
  sender.setZip(zip_code);

  cout << "\n\n";
}

/*Similar to the getSenderInfo function
 *This function is used to request and receive information from the user.
 *The information is used to set the values of a person that will be
 *passed to the instances of Package, ThreeDay, and OverrnightPackage.
 *It represents the "recipient" of the Package class.*/

void getRecipientInfo(Person& recipient){
	string temp1;
	int zip_code;

  cin.ignore(256, '\n');

  cout << "Enter the recipient's name: ";
  getline(cin, temp1);
  recipient.setName(temp1);

  cout << "Enter the recipient's street address: ";
  getline(cin, temp1);
  recipient.setAddress(temp1);

  cout << "Enter the recipient's city: ";
  getline(cin, temp1);
  recipient.setCity(temp1);

  cout << "Enter the recipient's state: ";
  getline(cin, temp1);
  recipient.setState(temp1);

  cout << "Enter the recipient's ZIP code: ";
  cin >> zip_code;
  recipient.setZip(zip_code);

  cout << "\n\n";
}

/*The above functions set the information for the sender and recipient
 *and was passed to the constructors of p1, p2, and p3.  In this
 *function you will use the instance of Package to get the sender
 *and recipient information then call printSenderInfo and
 *printRecipientInfo. */

void calculateAndPrint(Package& p1, ThreeDay& p2, OvernightPackage& p3){

  /*create an instance of Person and make it equal to the P1's sender
   *information.  Do the same with P1's recipient.  */
   Person a = p1.getSender();
   Person b = p1.getRecipient();
	 cout << endl;

   /*print the sender information*/
   a.printSenderInfo();

   /*print the recipient information*/
   b.printRecipientInfo();

   /*Since we are dealing with money make sure you set the precision to 2
   *and make sure sure trailing zeros are printed.*/
   cout << fixed << setprecision(2);


   /*Now you are to calculate and print the cost of the Package, ThreeDay,
   *and OvernightPackage  See the sample output.  */
   cout << "Cost calculation for Package: $" << p1.calculateCost() << endl;
   cout << "Cost calculation for ThreeDay: $" << p2.calculateCost() << endl;
	 cout << "Cost calculation for OvernightPackage: $" << p3.calculateCost();
   cout << endl;
}
