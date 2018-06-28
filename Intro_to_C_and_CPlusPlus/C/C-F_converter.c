// Converts degrees C to degrees F

#include <stdio.h>

int main(void)
{
	float degC, degF;
	degC = 0.0;
	degF = 0.0;

	printf("****CELCIUS ----> FAHRENHEIT****\n");
	printf("Enter a temperature to be converted: ");
	scanf("%g", &degC);
	printf("\n");

	degF = (1.8 * degC) + 32;

	printf("%g C = %g F\n", degC, degF);

	return(0);
}

