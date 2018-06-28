/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Programming Assignment #2
 * -> File containing all functions
 */

#include "tweetFunctions.h"

//finds the amount of characters in the longest tweet
int max_chars(char array[][MAX_TWEET_SIZE], int num_tweets){
  int i, mostCharsIndex = 0, mostCharsVal = 0;
  for(i = 1; i < num_tweets; i++){
    if(strlen(array[i]) > strlen(array[mostCharsIndex])){
      mostCharsVal = strlen(array[i]);
      mostCharsIndex = i;
		}
  }
  return mostCharsVal;
}

//finds the index of the longest tweet
int max_index(char array[][MAX_TWEET_SIZE], int num_tweets){
  int i, index = 0;
  for(i = 1; i < num_tweets; i++){
    if(strlen(array[i]) > strlen(array[index])){
      index = i;
    }
  }
  return index;
}

//finds the amount of characters in the shortest tweet
int min_chars(char array[][MAX_TWEET_SIZE], int num_tweets){
	int i, leastCharsIndex = 0, leastCharsVal = 0;
	for(i = 1; i < num_tweets; i++){
		if(strlen(array[i]) < strlen(array[leastCharsIndex])){
      leastCharsVal = strlen(array[i]);
			leastCharsIndex = i;
		}
	}
	return leastCharsVal;
}

//find the index of the shortest tweet
int min_index(char array[][MAX_TWEET_SIZE], int num_tweets){
	int i, index = 0;
	for(i = 1; i < num_tweets; i++){
		if(strlen(array[i]) < strlen(array[index])){
			index = i;
		}
	}
	return index;
}

//calculates & prints the frequency with which alphabetical letters
//appear in the tweet files
void character_frequency(char array[][MAX_TWEET_SIZE], int num_tweets){
    int frequency[26] = {0};
    double percentage[26] = {0};
    int i, row, col;

    char lowerChar = 'a', upperChar = 'A';

    for(i = 0; i < 26; i++){
      for(row = 0; row < num_tweets; row++){
        for(col = 0; col < strlen(array[row]); col++){
          if(array[row][col] == lowerChar || array[row][col] == upperChar){
            frequency[i] += 1;
          }                    
        }                                  
      }
      lowerChar++; //cycles through the alphabet
      upperChar++;
    }

    int totalChars = 0;
    for(i = 0; i < 26; i++){
      totalChars += frequency[i];
    }

    //populate the 'percentage' array
    for(i = 0; i < 26; i++){
      percentage[i] = (double)frequency[i] / totalChars;
    }

    printf("a: %.2lf\t\tb: %.2lf\t\tc: %.2lf\t\td: %.2lf\n", percentage[0],
            percentage[1], percentage[2], percentage[3]);
    printf("e: %.2lf\t\tf: %.2lf\t\tg: %.2lf\t\th: %.2lf\n", percentage[4],
            percentage[5], percentage[6], percentage[7]);
    printf("i: %.2lf\t\tj: %.2lf\t\tk: %.2lf\t\tl: %.2lf\n", percentage[8],
            percentage[9], percentage[10], percentage[11]);
    printf("m: %.2lf\t\tn: %.2lf\t\to: %.2lf\t\tp: %.2lf\n", percentage[12],
            percentage[13], percentage[14], percentage[15]);
    printf("q: %.2lf\t\tr: %.2lf\t\ts: %.2lf\t\tt: %.2lf\n", percentage[16],
            percentage[17], percentage[18], percentage[19]);
    printf("u: %.2lf\t\tv: %.2lf\t\tw: %.2lf\t\tx: %.2lf\n", percentage[20],
            percentage[21], percentage[22], percentage[23]);
    printf("y: %.2lf\t\tz: %.2lf\n", percentage[24], percentage[25]);

    return;
}

void sentiment(FILE *sentiments, int num_tweets){
  int  negative = 0, neutral = 0, positive = 0;
  char sentiment_vals[MAX_TWEETS][MAX_TWEET_SIZE];

  //read all sentiments into an array
  int i = 0;
  while(fgets(sentiment_vals[i], MAX_TWEET_SIZE, sentiments) != NULL){
    i++;
  }

  //sentiment evaluation is always the second char in each string,
  //so this loop only looks at the that char
  for(i = 0; i <= num_tweets; i++){
	  if(sentiment_vals[i][1] == '0'){
		  negative++;
		}
	  if(sentiment_vals[i][1] == '2'){
		  neutral++;
	  }
	  if(sentiment_vals[i][1] == '4'){
		  positive++;
	  }
  }

  printf("Polarity analysis:\n");
  printf("Negative tweets: %d(%.2lf%%)\n", negative, ((double)negative / num_tweets) * 100);
  printf("Neutral tweets: %d(%.2lf%%)\n", neutral, ((double)neutral / num_tweets) * 100);
  printf("Positive tweets: %d(%.2lf%%)\n", positive, ((double)positive / num_tweets) * 100);

  return;
}

//prints all tweets
void show_all(char array[][MAX_TWEET_SIZE], int num_tweets){
  int i;
  for(i = 0; i < num_tweets; i++){
    printf("%s\n", array[i]);
  }
  return;
}
