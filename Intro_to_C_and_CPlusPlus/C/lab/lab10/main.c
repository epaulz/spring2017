/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab 10
 * October 24, 2016
 * -file containing the 'main' function to bring all the 
 * -whole program together.
 */

#include "defs.h"

int arraySize = 20;

int main(void){
	int array1[arraySize];
	int array2[arraySize];
	int secondHighestValue1, secondHighestValue2;
	int innerProduct;

	printf("Enter %d integers: \n", arraySize); //prompt user
	arrayInitWithInput(array1);

	arrayInitWithRand(array2);	//no prompt necessary
	
	printf("\narray1: \n");
	printArray(array1);

	printf("\narray2: \n");
	printArray(array2);
	
	innerProduct = findInnerProduct(array1, array2);	//calculate prior to sorting

	sortingLoop(array1); //i used a bubble sort to put the arrays in ascending order
	sortingLoop(array2);	//then found the greatest/second greatest values from that
	
	secondHighestValue1 = findSecondHighestValue(array1);
	secondHighestValue2 = findSecondHighestValue(array2);

	printf("\nSecond highest value in array1 is %d.\n", secondHighestValue1);
	printf("Second highest value in array2 is %d.\n\n", secondHighestValue2);

	printf("Inner product is %d.\n", innerProduct);
	
	return 0;	//return of main function
}



