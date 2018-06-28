/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab 9
 * October 17, 2016
 * -this programs serves the same purpose as Lab 8 except this one
 * -utilizes user-defined functions to make it more modular.
 */

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void arrayInitWithInput(int myArray[]);

void arrayInitWithRand(int myArray[]);

void printArray(int myArray[], int size);

int  findInnerProduct(int myArray1[], int myArray2[]);

void sortingLoop(int myArray[]); //i added this function (explanation at call)

int  findHighestValue(int myArray[]);

int  findSecondHighestValue(int myArray[]);

int main(void){
	int array1[20];
	int array2[20];
	int secondHighestValue1, secondHighestValue2;
	int innerProduct;

	printf("Enter 20 integers: \n"); //prompt user
	arrayInitWithInput(array1);

	arrayInitWithRand(array2);	//no prompt necessary
	
	printf("\narray1: \n");
	printArray(array1, 20);

	printf("\narray2: \n");
	printArray(array2, 20);
	
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

//initializes & populates array with user input
void arrayInitWithInput(int myArray[]){
	int i;
	for(i = 0; i < 20; i++){
		scanf("%d", &myArray[i]);
	}
}

//initializes & populates array with random set of numbers
void arrayInitWithRand(int myArray[]){
	int i;
	for(i = 0; i < 20; i++){
		myArray[i] = rand() % 50 + 1;
	}
}

//prints the array
void printArray(int myArray[], int size){
	int i;
	for(i = 0; i < 20; i++){
		printf("%d\n", myArray[i]);
	}
}

//calculates inner product of 2 arrays
int findInnerProduct(int myArray1[], int myArray2[]){
	int i, product = 0;
	for(i = 0; i < 20; i++){
		product += (myArray1[i] * myArray2[i]);
	}
	return product;
}

//sorts array into ascending order
void sortingLoop(int myArray[]){
	int i, j, swap;
	for(i = 0; i < 19; i++){
		for(j = 0; j < (19 - i); j++){
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
	int highestVal = myArray[19];

	return highestVal;
}

//find second highest value in array (using return value of 'findHighestValue')
int findSecondHighestValue(int myArray[]){
	int highest, second_highest, i;

	highest = findHighestValue(myArray);

	for(i = 19; myArray[i] == highest; i--){
		second_highest = myArray[i-1];
	}

	return second_highest;
}
