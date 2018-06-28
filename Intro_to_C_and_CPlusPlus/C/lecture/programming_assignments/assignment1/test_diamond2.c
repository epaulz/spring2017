#include <stdio.h>

int main(void){
	char usr_char;
	int usr_rows;
	int screen_width = 80;
	int i, j, k, space;

	printf("-----CHARACTER DIAMOND-----\n");
	printf("Enter a character: ");
	scanf("%c", &usr_char);

	printf("Enter an odd number between 1 and 40 (rows): ");
	scanf("%d", &usr_rows);

	//Print top half of diamond
	space = (screen_width / 2) - 1;
	for(i = 0; i < (usr_rows / 2) + 1; i++){
		for(j = 0; j < space; j++){
			printf(" ");
		}
		char c = usr_char - 1;
		for(k = space + 1; k < (screen_width - space); k++){
			if(k <= (screen_width / 2)){
				printf("%c", ++c);
			}
			else if(k > (screen_width / 2)){
				printf("%c", --c);
	   	}
		}
		printf("\n");
		space -= 2;
	}

	//Print bottom half of diamond
	space = (screen_width / 2) - (usr_rows - 2);
	for(i = 0; i < (usr_rows / 2); i++){
		for(j = 0; j < space; j++){
			printf(" ");
		}
		char c = usr_char - 1;
		for(k = space + 1; k < (screen_width - space); k++){
			if(k <= (screen_width / 2)){
				printf("%c", ++c);
			}
			else if(k > (screen_width / 2)){
				printf("%c", --c);
			}
		}
		printf("\n");
		space += 2;
	}

	return(0);
}
