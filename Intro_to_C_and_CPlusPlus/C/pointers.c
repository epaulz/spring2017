#include <stdio.h>

int main(void){
	int num1;
	num1 = 3;

	int *ptr1;
	ptr1 = &num1;

	num1 = 5;

	printf("4: Prediction >> 5\n"); 
	printf("%i\n\n", *ptr1);
	
	*ptr1 = 9;
	printf("6: Prediction >> 9\n");
	printf("%i\n\n", num1);

	int *ptr2;
	ptr2 = ptr1;
	printf("8: Prediction >> 9\n");
	printf("%i\n\n", *ptr2);

	int const *ptr3;
	ptr3 = num1;
	printf("10: Prediction >> 9\n");
	printf("%i\n\n", *ptr3);

	return 0;
}
