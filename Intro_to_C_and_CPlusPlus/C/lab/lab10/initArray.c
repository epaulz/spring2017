/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab 10
 * October 24, 2016
 * -file containing functions to initialize the two arrays
 */

#include "defs.h"

//initializes & populates array with user input
void arrayInitWithInput(int myArray[]){
	int i;
	for(i = 0; i < arraySize; i++){
		scanf("%d", &myArray[i]);
	}
}

//initializes & populates array with random set of numbers
void arrayInitWithRand(int myArray[]){
	int i;
	for(i = 0; i < arraySize; i++){
		myArray[i] = rand() % 50 + 1;
	}
}

