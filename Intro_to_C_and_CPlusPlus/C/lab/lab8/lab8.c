/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab #8
 * October 9, 2016
 * -this program asks the user to enter 20 integers which will
 * -populate an array.  it then populates another array with a
 * -random set of integers between 1-50 and compares the two.
 * -it then prints out the second highest number from each array
 * -as well as the inner product of the arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	const int num_vals = 20;
	int array1[20];
	int array2[20];
	int i, j, temp;
	int second_highest1 = 0;
	int second_highest2 = 0;

	printf("Enter 20 integers: \n\n");

	// populate array1
	printf("array1: \n");
	for(i = 0; i < num_vals; i++){
		scanf("%d", &array1[i]);
	}
	
	printf("\n");

	// populate array2
	printf("array2: \n");
	for(i = 0; i < num_vals; i++){
		array2[i] = rand() % 50 + 1;
	}
	
	// print array2
	for(i = 0; i < num_vals; i++){
		printf("%d\n", array2[i]);
	}
	
	// calculate inner product (before sorting)
	int sum = 0;
	for(i = 0; i < num_vals; i++){
		sum = sum + (array1[i] * array2[i]);
	}

	// loop to sort arrays in ascending order
	for(i = 0; i < num_vals - 1; i++){
		for(j = 0; j < num_vals - i - 1; j++){
			if(array1[j] > array1[j+1]){
				temp = array1[j];
				array1[j] = array1[j+1];
				array1[j+1] = temp;
			}
			if(array2[j] > array2[j+1]){
				temp = array2[j];
				array2[j] = array2[j+1];
				array2[j+1] = temp;
			}
		}
	}
	
	// account for duplicate numbers and find second largest
	// values in both arrays
	if(array1[num_vals - 1] == array1[num_vals - 2]){
		for(i = (num_vals - 1); array1[i] == array1[i-1]; i--){
			second_highest1 = array1[i-2];
		}
	}
	else if(array1[num_vals - 1] > array1[num_vals - 2]){
		second_highest1 = array1[num_vals-2];
	}

	if(array2[num_vals - 1] == array2[num_vals - 2]){
		for(i = (num_vals - 1); array2[i] == array2[i-1]; i--){
			second_highest2 = array2[i-2];
		}
	}
	else if(array2[num_vals - 1] > array2[num_vals - 2]){
		second_highest2 = array2[num_vals-2];
	}

	printf("\n");
	printf("second highest from array1 is: %d\n", second_highest1);
	printf("second highest from array2 is: %d\n\n", second_highest2);
 
	printf("inner product is: %d\n", sum);

	return(0);
}

