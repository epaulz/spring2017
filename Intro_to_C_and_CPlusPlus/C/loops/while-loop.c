#include <stdio.h>

int main(void)
{
	int n = 1, triNum = 0;

	while(n<=5)
	{
		triNum += n;
		n++;
	}
	printf("Triangular number is %d\n", triNum);

	return(0);
}

