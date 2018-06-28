/* Eric Paulz
 * CPSC 1010 - Fall 2016
 * Programming Assignment #2
 * -> Header file
 */
 
#ifndef tweetFunctions_h
#define tweetFunctions_h

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX_TWEET_SIZE 200
#define MAX_TWEETS 1000

int max_chars(char array[][MAX_TWEET_SIZE], int num_tweets);
int max_index(char array[][MAX_TWEET_SIZE], int num_tweets);
int min_chars(char array[][MAX_TWEET_SIZE], int num_tweets);
int min_index(char array[][MAX_TWEET_SIZE], int num_tweets);
void character_frequency(char array[][MAX_TWEET_SIZE], int num_tweets);
void sentiment(FILE *sentiments, int num_tweets);
void show_all(char array[][MAX_TWEET_SIZE], int num_tweets);

#endif
