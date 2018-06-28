/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab #3
 * 09-05-2016
 * --- DESCRIPTION ---
 * This program uses initialized variables to create expressions that will then
 * be assigned to other variables and prints all of the results.  We used the 
 * 'fprintf(' function, so if you want the output to go somewhere other than
 * your monitor simply change each stdout argument to your desired location.
 */

/* --- #10 ANSWER ---
 * After assigning values to intVar3, intVar4, exp3 and exp4 I tried to compile and
 * run the program.  However, it only printed the initial section of the program 
 * followed by "Floating point exception."  This is because we had division by
 * ZERO in our exp4 expression.  3/5 will truncate to ZERO automatically since it
 * is integer division and the result is <1.
 */

#include <stdio.h>

int main(void)
{
	// Declare/initialize variables
	int intVar1 = 4;
	int intVar2 = 3;
	int intVar3, intVar4;

	int exp1, exp2, exp3, exp4;
	
	// Section 1
	exp1 = intVar1 + (5 * (intVar2 / 3)) * intVar1;
	exp2 = ((intVar1 + 5) * intVar2) / (3 * intVar1);

	fprintf(stdout, "intVar1 = %d and intVar2 = %d\n\n", intVar1, intVar2);
	fprintf(stdout, "Expression values are:\n");
	fprintf(stdout, "exp1 = %d\n", exp1);
	fprintf(stdout, "exp2 = %d\n\n", exp2);
	
	// Section 2
	intVar3 = 3;
	intVar4 = 5;

	exp3 = intVar3 + ((4 * intVar4) / (3 * intVar3));
	exp4 = (intVar4 % 2) / (intVar4 / intVar3);

	fprintf(stdout, "intVar3 = %d and intVar4 = %d\n\n", intVar3, intVar4);
	fprintf(stdout, "Expression values are:\n");
	fprintf(stdout, "exp3 = %d\n", exp3);
	fprintf(stdout, "exp4 = %d\n", exp4);


	return(0);
}

