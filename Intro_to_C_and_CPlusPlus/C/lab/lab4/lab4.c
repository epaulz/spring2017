/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab #4
 * - This program allows a user to input a character along with dimensions of length and
 * - height.  It then creates a rectangle using the character and dimensions that were
 * - entered.
 */

#include <stdio.h>

int main(void){
	char usr_input;
	int length = 0, height = 0;
	int rows, cols;
	
	// Request char input
	fprintf(stdout, "Enter a character: ");	fscanf(stdin, "%c", &usr_input);
	fprintf(stdout, "\n");
	
	// Print char's numerical values
	fprintf(stdout, "Your character '%c' has these numerical values:\n", usr_input);
	fprintf(stdout, "DECIMAL   OCTAL     HEX\n");
	fprintf(stdout, "%-10d%#-10o%#-10x", usr_input, usr_input, usr_input);
	fprintf(stdout, "\n\n");
	
	fprintf(stdout, "Now we will draw a rectangle with your character!\n");
	fprintf(stdout, "Enter two integers... these will be the dimensions of ");
	fprintf(stdout, "your rectangle.\n");
	
	// Gather dimension input
	fprintf(stdout, "Length: ");	fscanf(stdin, "%d", &length);
	fprintf(stdout, "Height: ");	fscanf(stdin, "%d", &height);
	fprintf(stdout, "\n");

	// Print hollow rectangle using nested loops
	for(rows = 0; rows < height; rows++){
		for(cols = 0; cols < length; cols++){
			if(rows == 0 || rows == height - 1){
				fprintf(stdout, "%c", usr_input);
			}
			if(cols == 0 || cols == length - 1){
				fprintf(stdout, "%c", usr_input);
			}
			else{
				fprintf(stdout, " ");
			}
		}
	
	fprintf(stdout, "\n");
	}

	return(0);
}

