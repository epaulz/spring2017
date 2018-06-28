/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab #6
 * - This program asks the user to input an integer, then outputs the square root of
 * - that integer as well as stating whether the digits are all even, all odd, or a mix
 * - of the two.  The user can use the program as many times as they want until a '0' is
 * - entered.
 */

#include <stdio.h>
#include <math.h>

int main(void){
	int usr_int;
	int again = 2;

	do{
		printf("Enter a three-digit integer: ");
		scanf("%d", &usr_int);

		double sqr_root = sqrt(usr_int);
		printf("The square root of %d is %.2lf.", usr_int, sqr_root);
		printf("\n");

		if((usr_int % 2 == 0) && ((usr_int / 10) % 2 == 0) && ((usr_int / 100) % 2 == 0)){
			printf("Your integer contains only EVEN digits.\n");
		}
		
		else if((usr_int % 2 == 1) && ((usr_int / 10) % 2 == 1) && ((usr_int / 100) % 2 == 1)){
			printf("Your integer contains only ODD digits.\n");
		}

		else{
			printf("Your integer contains a mix of EVEN and ODD digits.\n");
		}

		printf("\n");
		
		printf("Do you want to go again? (1 for yes, 0 for no): ");
		scanf("%d", &again);

		while((again != 0) && (again != 1)){
			printf("Invalid input.  Enter a 1 for yes, 0 for no: ");
			scanf("%d", &again);
		}
		
	}	while(again == 1);


	return 0;
}

