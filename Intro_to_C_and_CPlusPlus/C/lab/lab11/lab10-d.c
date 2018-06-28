#include <stdio.h>

int main(void){

	int x = 10;
	int *px = &x;

	int a[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
	int b[5] = {1000, 1000, 1000, 1000, 1000};

	int *p1 = a;
	int *p2 = b;

	int (*parray)[] = &b;

	int *ap1[3];
	ap1[0] = &x;
	ap1[1] = p1;
	ap1[2] = b;

	int (*ap2[2])[10];
	ap2[0] = &(*parray);
	ap2[1] = parray;

//	int i;
//	for(i = 0; i < 10; i++){
//		printf("%d\n", *parray[i]);
//	}


	printf("%p\n", p1);
	printf("%p\n", p2);
	printf("%p\n", parray);
	return 0;
}
