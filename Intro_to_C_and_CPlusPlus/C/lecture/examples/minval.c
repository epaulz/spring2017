#include <stdio.h>

int sort(int array[], int size);

int main(void){
	int array1[5] = {157, -28, -37, 26, 10};
	int array2[6] = {12, 45, 1, 10, 3, 22};
	int min1, min2;

	min1 = sort(array1, 5);
	min2 = sort(array2, 6);

	printf("Lowest value of array1 is %d.\n", min1);
	printf("Lowest value of array2 is %d.\n", min2);
	
	return 0;
}

int sort(int array[], int size){
	int i, j, temp, minVal;

	//Code to find the min value
	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	minVal = array[0];

	return(minVal);
}



