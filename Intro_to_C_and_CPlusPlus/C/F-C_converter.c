// Converts degrees F to degrees C

#include <stdio.h>

int main(void)
{
	float degF, degC;
	degF = 0.0;
	degC = 0.0;

	printf("****FAHRENHEIT ----> CELCIUS****\n");
	printf("Enter a temperature to be converted: ");
	scanf("%g", &degF);
	printf("\n");

	degC = (degF - 32) / 1.8;

	printf("%g F = %g C\n", degF, degC);

	return(0);
}



