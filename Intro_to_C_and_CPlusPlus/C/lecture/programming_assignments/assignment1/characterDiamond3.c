/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * October 10, 2016
 * -this program will ask the user to input a character,
 * -then print a diamond using that character as a border
 * -while increment/decrementing the inside to produce more
 * -characters.  this program accounts for errant values that
 * -will produce inconsistent results.
 */

#include <stdio.h>

int main(void){
	char usr_char;
	int usr_rows = 2;
	int screen_width = 80;
	int i, j, k, space;
	int rows_allowed = 40;

	printf("This program will print a character diamond.\n\n");
	
	printf("Enter a character: ");
	scanf("%c", &usr_char);
	
	switch(usr_char){
		case 'Y':
		case 'Z':
			rows_allowed = 38;
			break;
		case '[':
		case '\\':
			rows_allowed = 36;
			break;
		case ']':
		case '^':
			rows_allowed = 34;
			break;
		case '_':
		case '`':
			rows_allowed = 32;
			break;
		case 'a':
		case 'b':
			rows_allowed = 30;
			break;
		case 'c':
		case 'd':
			rows_allowed = 28;
			break;
		case 'e':
		case 'f':
			rows_allowed = 26;
			break;
		case 'g':
		case 'h':
			rows_allowed = 24;
			break;
		case 'i':
		case 'j':
			rows_allowed = 22;
			break;
		case 'k':
		case 'l':
			rows_allowed = 20;
			break;
		case 'm':
		case 'n':
			rows_allowed = 18;
			break;
		case 'o':
		case 'p':
			rows_allowed = 16;
			break;
		case 'q':
		case 'r':
			rows_allowed = 14;
			break;
		case 's':
		case 't':
			rows_allowed = 12;
			break;
		case 'u':
		case 'v':
			rows_allowed = 10;
			break;
		case 'w':
		case 'x':
			rows_allowed = 8;
			break;
		case 'y':
		case 'z':
			rows_allowed = 6;
			break;
		case '{':
		case '|':
			rows_allowed = 4;
			break;
		case '}':
		case '~':
			rows_allowed = 1;
			break;
	}

	while(usr_rows % 2 == 0 || usr_rows < 1 || usr_rows > rows_allowed){
		printf("Enter an odd number between 1 and %d (rows): ", rows_allowed);
		scanf("%d", &usr_rows);
	}

	//Print top half of diamond
	space = (screen_width / 2) - 1;
	for(i = 0; i <= (usr_rows / 2); i++){
		for(j = 0; j <= space; j++){
			printf(" ");
		}
		char c = usr_char - 1;
		for(k = (space + 1); k < (screen_width - space); k++){
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
		for(j = 0; j <= space; j++){
			printf(" ");
		}
		char c = usr_char - 1;
		for(k = (space + 1); k < (screen_width - space); k++){
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
