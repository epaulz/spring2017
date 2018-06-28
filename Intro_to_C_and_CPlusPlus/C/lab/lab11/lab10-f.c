#include <stdio.h>

int main(void){

	int x = 10;
	int *xPtr = &x;
	x++;
	(*xPtr)++;
	printf("x is %d\n", *xPtr);

	char c = 'X', d = 'Y';
	char * const cPtr = &c;
	printf("c is %c\n", *cPtr);
//	cPtr = &d;

	const char *dPtr = &d;
//	*dPtr = 'Z';
	d = 'Z';
	printf("d is %c\n", *dPtr);

	return 0;
}
