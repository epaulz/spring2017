/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab 10
 * October 24, 2016
 * -header file containing #includes and all function prototypes
 */

#include <stdio.h>
#include <stdlib.h>

extern int arraySize;

//function prototypes
void arrayInitWithInput(int myArray[]);

void arrayInitWithRand(int myArray[]);

void printArray(int myArray[]);

int findInnerProduct(int myArray1[], int myArray2[]);

void sortingLoop(int myArray[]);

int findHighestValue(int myArray[]);

int findSecondHighestValue(int myArray[]);
