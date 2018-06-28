/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Lab #12
 * November 14, 2016
 * -this program takes command line arguments and creates a 
 * -histogram using the input.  it also calculates the sum
 * -of the divisors of the integer entered by the user.
 */
 
#include <stdio.h>

int sumOfDivisors(int aNum);

int main(int argc, char *argv[]){
	int userNum, sum, i, j;
	char userChar;

	sscanf(argv[1], "%d", &userNum);
	sscanf(argv[2], "%c", &userChar);
	
	for(i = 2; i <= userNum; i++){
		sum = sumOfDivisors(i);
		printf("%-3d", i);
		
		for(j = 1; j <= sum; j++){
			printf("%c", userChar);
		}
		
		printf("\n");
	}
	
	return 0;
}

int sumOfDivisors(int aNum){
	int i, sum = 0;

	for(i = 1; i < aNum; i++){
		if(aNum % i == 0){
			sum += i;
	 	}
  	}	 
      

	return sum;
}

