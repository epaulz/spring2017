/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Programming Assignment #2
 * -> File containing 'main' function
 */

#include "tweetFunctions.h"

int main(int argc, char* argv[]){

FILE *tweetFile, *sentimentFile;
char tweets[MAX_TWEETS][MAX_TWEET_SIZE];
int num_tweets = 0;

  // check number of command-line arguments
  if ( argc < 4 ) {
	/* argc should be 4 for correct execution */
	/* We print argv[0] assuming it is the program name */
    printf( "usage: %s Candidate_name tweet_file sentiment_file ", argv[0] );
    return 1;
  } // end if

  else{
  	// open the file of tweets
	   if ((tweetFile = fopen(argv[2], "r"))  ==  NULL ) {
       printf("Can't open tweet file %s.\n", argv[2]);
       return 2;
	   }
    // open the file of sentiment analysis results
	   if ((sentimentFile = fopen (argv[3], "r"))  ==  NULL ) {
       printf("Can't open sentiment file %s.\n", argv[3]);
       return 3;
	   }
  } // end else

  printf("                 Analysis of tweets from %s \n", argv[1]);
  printf("============================================================== \n");


  // Read the tweets from the file into the tweets array, using fgets
  // Assume that <= MAX_TWEETS tweets are in the file
  // Use num_tweets to keep track of how many you read
  int i = 0;
  while(fgets(tweets[i], MAX_TWEET_SIZE, tweetFile) != NULL){
    i++;
    num_tweets++;
  }

  fclose(tweetFile);

  // Print out the number of tweets read.
  printf("Located %d tweets from %s.\n\n", num_tweets, argv[2]);

  // Print out the index (array subscript) of the longest tweet, the
  // number of characters in that tweet and the text of the tweet.
  printf("The longest tweet is #%d.  It contains %d characters: \n %s\n\n",
  			 max_index(tweets,num_tweets), max_chars(tweets,num_tweets),
	       tweets[max_index(tweets,num_tweets)]);

  // Print out the index (array subscript) of the shortest tweet, the
  // number of characters in that tweet and the text of the tweet.
  printf("The shortest tweet is #%d. It contains %d characters: \n %s\n\n",
         min_index(tweets,num_tweets), min_chars(tweets,num_tweets),
			   tweets[min_index(tweets,num_tweets)]);

  // Print out a separator line
  printf("            ------------------------------------------------------       \n");
  printf("\n");

  // Print out a table of the alphabetic character frequenices in the tweets
  // Ignore case (i.e., just report frequencies of a ... z
  printf("Character frequencies in %s are: \n\n", argv[2]);
  character_frequency(tweets, num_tweets);
  printf("\n");

  // Print out a separator line
  printf("            ------------------------------------------------------       \n");
  printf("\n");

  // Report the number and percentages of negative(0), neutral(2) and
  // positive(4) tweets based on the integers prepended to each tweet, as
  // seen in the "sentiments" file.
  printf("An analysis of the tweets in %s as listed in %s:\n", argv[2], argv[3]);
  sentiment(sentimentFile, num_tweets);
  printf("\n");

  // Print out a separator line
  printf("            ------------------------------------------------------       \n");
  printf("\n");

  // List all the tweets
  printf("The full listing of the tweets in %s: \n", argv[2]);
  show_all(tweets,num_tweets);

return 0;

}
