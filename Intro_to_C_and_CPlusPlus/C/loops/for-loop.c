#include <stdio.h>

int main(void)
{
	int n, triNum = 0;

	for(n=1; n<=5; n++)
	{
		triNum = triNum + n;
	}
	printf("Triangular number is %d\n", triNum);

	return(0);
}

