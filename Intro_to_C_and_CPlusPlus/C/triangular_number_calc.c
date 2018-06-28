// Asking the User for Input

#include <stdio.h>

int main(void)
{
	int n, number, triangularNumber;

	printf("What triangular number do you want to be calculated?: ");
	scanf("%i", &number);
	printf("\n");

	for(n = 1; n <= number; ++n)
		triangularNumber += n;

	printf("Triangular number %i is: %i", number, triangularNumber);
	printf("\n");

	return(0);
}

