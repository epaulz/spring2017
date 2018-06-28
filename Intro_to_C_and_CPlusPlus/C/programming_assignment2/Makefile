# Eric Paulz
# CPSC 1010 - Fall 2016
# Programming Assignment #2
# -> Makefile

tweetStats:	tweetStats.c tweetFunctions.c tweetFunctions.h
	gcc -Wall -o tweetStats tweetStats.c tweetFunctions.c

donald: tweetStats
	./tweetStats Donald_Trump donald.txt donald_sentiments.txt > donald_report.txt

hillary: tweetStats
	./tweetStats Hillary_Clinton hillary.txt hillary_sentiments.txt > hillary_report.txt

clean:
	rm tweetStats
	rm donald_report.txt
	rm hillary_report.txt
