#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumOfDivisors(int aNum);

typedef struct{
	int line_number;
	int sum_of_divisors;
	char value[10];
} output;

int main(int argc, char *argv[]){
	int userNum, i, k;
	char userChar;

	sscanf(argv[1], "%d", &userNum);
	sscanf(argv[2], "%c", &userChar);

	output *outputs = (output*)malloc((userNum-2)*sizeof(output));

	for(i = 2; i <= userNum; i++){
		int j = i - 2;
		
		outputs[j].line_number = i;
		outputs[j].sum_of_divisors = sumOfDivisors(i);

		if(outputs[j].sum_of_divisors == i){
			strcpy(outputs[j].value, "Perfect  ");
		}
		else if(outputs[j].sum_of_divisors < i){
			strcpy(outputs[j].value, "Deficient");
		}
		else if(outputs[j].sum_of_divisors > i){
			strcpy(outputs[j].value, "Abundant ");
		}

		printf("%3d is %s\t", outputs[j].line_number, outputs[j].value);

		for(k = 0; k < outputs[j].sum_of_divisors; k++){
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
