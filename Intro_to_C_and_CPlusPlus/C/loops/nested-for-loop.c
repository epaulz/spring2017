#include <stdio.h>

int main(void)
{
	int n, triNum, number, counter;
	for(counter = 1; counter <=5; counter++)
	{
		printf("What triangular number do you want?: \n");
		scanf("%d\n", &number);
		triNum = 0;
		for(n = 1; n <= number; n++)
		{
			triNum += n;
		}
		printf("Triangular number for %d is %d\n", number, triNum);
	}
	return(0);
}

