/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab 10
 * October 24, 2016
 * -file containing functions to find inner product, highest,
 * -and second highest values in the arrays.
 */

#include "defs.h"

//calculates inner product of 2 arrays
int findInnerProduct(int myArray1[], int myArray2[]){
	int i, product = 0;
	for(i = 0; i < arraySize; i++){
		product += (myArray1[i] * myArray2[i]);
	}
	return product;
}

//sorts array into ascending order
void sortingLoop(int myArray[]){
	int i, j, swap;
	for(i = 0; i < (arraySize - 1); i++){
		for(j = 0; j < (arraySize - i - 1); j++){
			if(myArray[j] > myArray[j+1]){
				swap = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = swap;
			}
		}
	}
}

//find highest value in array
int findHighestValue(int myArray[]){
	int highestVal = myArray[arraySize - 1];

	return highestVal;
}

//find second highest value in array (using return value of 'findHighestValue')
int findSecondHighestValue(int myArray[]){
	int highest, second_highest, i;

	highest = findHighestValue(myArray);

	for(i = (arraySize - 1); myArray[i] == highest; i--){
		second_highest = myArray[i-1];
	}

	return second_highest;
}
