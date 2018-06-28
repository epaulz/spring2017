/* Eric Paulz
 * CPSC 1010 Fall 2016
 * Lab #2
 * - This program lets the user input the dimensions of any triangle and
 * - returns the total area of said triangle.
 */

/* If the user inputs 3 for triangle base and 5 for triangle height, the 
 * program returns a result of 7.  The true result of (3 * 5) / 2 should be
 * 7.5, but since we are using int and not float the program automatically 
 * truncates the output to its integer value.
 */

#include <stdio.h>

int main(void)
{
	int triBase = 0;
	int triHeight = 0;
	int triArea = 0;	// Change colon to semi-colon

	// Get user input
	printf("Enter triangle base (cm): ");	// Fix printf( and missing ';'
	scanf("%d", &triBase);	// Missing " after %d

	printf("Enter triangle height (cm): ");	// Missing " before )
	scanf("%d", &triHeight);	// add & before triHeight
	
	// Calculate triangle area
	triArea = (triBase * triHeight) / 2; // Take this line out of comments

	
	// Print triangle base, height, area
	printf("Triangle area = (");
	printf("%d", triBase);	// Missing comma after "
	printf(" * ");
	printf("%d", triHeight);	// Add "%d" to display variable
	printf(") / 2 = ");
	printf("%d", triArea);
	printf(" cm^2\n");

	return(0);

}

