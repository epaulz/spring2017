#include <stdio.h>

int main(int argc, char* argv[]){
	int integer1, *p1, **p2;

	integer1 = 10;
	p1 = &integer1;
	p2 = &p1;

/* printf("integer1 = %d\n", integer1);
   printf("p1 = %p\n", p1);
	printf("p2 = &p\n", p2);
*/

/*	(*p1)++;
	printf("integer1 = %d\n", *p1);
*/

/*	integer1++;
	printf("integer1 = %d\n", *p1);
*/

	*p1++;
	printf("integer1 = %d\n", *p1);

	return 0;
}
