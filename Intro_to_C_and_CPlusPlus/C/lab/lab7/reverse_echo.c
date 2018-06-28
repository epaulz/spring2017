/*	Eric Paulz
 * CPSC 1010 - Fall 2016
 *	Lab 7
 *	October 3, 2016
 *	- This program takes arguments from the command line and then
 *	- prints those arguments back in reverse order.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;

	printf("argc is:  %d\n", argc);	

	// completed for loop 
	for(i = (argc - 1); i > 0; i--){
		printf("%s ", argv[i]);			//%s to allow strings
	}

	printf("\n\n");

	return 0;
}
