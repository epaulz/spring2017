/* Class implementation for Package. Threeday and Overnight Package
   are derived classes */
/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/

#include "Package.h"

/*Use intialization list to initialize packages sender and recipient variables.
 The remaining variables will be initialized in the constructor*/

Package::Package(Person s, Person r, double w, double c) : sender(s),
  recipient(r){
    /*Complete the following code*/
   // if weight is zero, intialize it to 5 ounces
   if(w == 0){
     weight = 5;
   }
   else
		weight = w;

   // if cost is zero, intialize it to 25 cents
   if(c == 0){
     cost = .25;
   }
	 else
		cost = c;
}

/*I will provide the implementation for this function.  However ThreeDay and
 *OvernightPackage will need to override this function to meet add the additional
 *cost.  */
double Package::calculateCost(){
   return (weight*cost);
}

Person& Package::getSender(){
  return sender;
}
Person& Package::getRecipient(){
  return recipient;
}
