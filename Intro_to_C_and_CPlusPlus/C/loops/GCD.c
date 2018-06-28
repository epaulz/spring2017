#include <stdio.h>

int main(void){
	int numA = 0;
	int numB = 0;

	printf("Enter first positive integer: ");
	scanf("%d", &numA);

	printf("Enter second positive integer: ");
	scanf("%d", &numB);

	while(numA != numB){
		
		if(numA > numB){
			numA -= numB;
			printf("A=%d, B=%d", numA, numB);
			printf("\n");
		}
		else{
			numB -= numA;
			printf("A=%d, B=%d", numA, numB);
			printf("\n");
		}
	}
	printf("GCD is: %d\n", numA);

	return(0);
}


