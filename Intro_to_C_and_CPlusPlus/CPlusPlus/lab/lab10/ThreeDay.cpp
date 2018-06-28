/* Class implementation for a 3 day package */
/*
	Eric Paulz and Mitchell Bowser
	epaulz
	mbowser
	Lab 10, Section 004
	CPSC 1021
	TA: Nick Glyder
*/

#include "ThreeDay.h"

/*Complete this code*/

/*This is a constructor.
 *Use member initialization to initialize the information for the base
 *class (Package)  Then follow the instruction included to complete
 *the remaining information for the constructor.*/

ThreeDay::ThreeDay(Person s, Person r, double w, double c, double f) :
  Package(s,r,w,c), additionalFee(f){
   // if additional fee is negative, intialize it to ten cents
   if(f < 0){
     additionalFee = .10;
   }
	 else
		 additionalFee = f;
}

/*This function calls the packages calculateCost function,
 *then adds (weight * additionalFee) to it */
double ThreeDay::calculateCost(){
  double x = weight * additionalFee;
  return (x + Package::calculateCost());
}
