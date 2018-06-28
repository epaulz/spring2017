#include <stdio.h>
#include <string.h>

int main(void){
	int numArray[] = {1, 3, 5, 7, 9};
	char firstName[10] = "Jimmy";
	char lastName[15];
	strcpy(lastName, "Smith");

	char *ptr1 = lastName;
	printf("lastName is %s\n", lastName);
	printf("ptr1 is %s\n\n", ptr1);

	ptr1 = "Miller";
	printf("lastName is %s\n", lastName);
	printf("ptr1 is %s\n", ptr1);

	return 0;
}
