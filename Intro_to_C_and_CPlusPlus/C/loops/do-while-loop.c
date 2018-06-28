#include <stdio.h>

int main(void)
{
	int n=1, triNum=0;

	do 
	{
		triNum += n;
		n++;
	} while(n <= 5);

	printf("Triangular number is %d\n", triNum);

	return(0);
}

