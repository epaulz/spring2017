#include <stdio.h>

int main(){
	int i;

	fprintf(stdout, "P6\n200 200 255\n");
	
	for(i = 0; i < (200 * 200); i++){
		fprintf(stdout, "%c%c%c", 32, 83, 55);
	}

	return 0;
}
