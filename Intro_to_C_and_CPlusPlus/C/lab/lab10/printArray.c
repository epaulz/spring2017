/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab 10
 * October 24, 2016
 * -file containing the function to print an array
 */

#include "defs.h"

//prints the array
void printArray(int myArray[]){
	int i;
	for(i = 0; i < arraySize; i++){
		printf("%d\n", myArray[i]);
	}
}

