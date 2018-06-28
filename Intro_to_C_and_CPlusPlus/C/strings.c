#include <stdio.h>
#include <string.h>

int compare(char wordA[], char wordB[]);

int main(void){
	char word1[81], word2[81];
	int same;

	printf("\nEnter two words:  ");
	scanf("%s%s", word1, word2);
	printf("The words you entered are: %s %s\n\n", word1, word2);

	same = compare(word1, word2);
	if(same == 1)
		printf("YES\n\n");
	else
		printf("NO\n\n");

	return 0;
}

int compare(char wordA[], char wordB[]){
	int i, j;
	
	for(i = 0; wordA[i] != '\0'; i++);
	for(j = 0; wordB[j] != '\0'; j++);

	if((wordA[i-1] == wordB[j-1]) && (wordA[0] == wordB[0]))
		return 1;
	else
		return 0;
}
	


		
