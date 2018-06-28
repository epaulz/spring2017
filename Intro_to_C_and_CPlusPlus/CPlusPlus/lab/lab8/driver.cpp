/*
 * Eric Paulz
 * epaulz@clemson.edu
 * Lab #8
 * CPSC 1021-004
 * Nick Glyder
 */

#include "Date.h"

int main(int argc, char* argv[]){
  // declare a vector of Date objects called 'dates'
  vector<Date> dates;
  int numDates, i, mdy[3];
  int lowYear, lowMonth, lowDay;

  // declare file pointers and open files
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  // check for command line input and that files opened properly
  if(argc != 3){
    cout << "Please enter your command in the following format: ";
    cout << "<program> <input_file> <output_file>\n";
    return 1;
  }
  if(!input.is_open()){
    cout << "Input file could not be opened.\n";
    return 1;
  }
  if(!output.is_open()){
    cout << "Output file could not be opened.\n";
    return 1;
  }

  // read in number of dates
  input >> numDates;

  // populate vector 'dates' with input
  for(i = 0; i < numDates; i++){
    input >> mdy[0];
    input >> mdy[1];
    input >> mdy[2];

    dates.push_back(Date(mdy[0], mdy[1], mdy[2]));
  }

  // set 'lowest' variables to compare
  lowYear = dates.at(0).getYear();
  lowMonth = dates.at(0).getMonth();
  lowDay = dates.at(0).getDay();

  // loop that changes 'lowest' variables if conditions are right
  for(i = 1; i < numDates; i++){
    if(dates.at(i).getYear() < lowYear){
      lowYear = dates.at(i).getYear();
    }
    if(dates.at(i).getYear() == lowYear && dates.at(i).getMonth() < lowMonth){
      lowMonth = dates.at(i).getMonth();
      lowDay = dates.at(i).getDay();
    }
    if(dates.at(i).getYear() == lowYear && dates.at(i).getMonth() == lowMonth
       && dates.at(i).getDay() < lowDay){
         lowDay = dates.at(i).getDay();
    }
  }

  // array of strings to match up with the month number
  string monthNames[12] = {"January", "February", "March", "April", "May",
                           "June", "July", "August", "September", "October",
                           "November", "December"};

  // print oldest date to output file
  output << monthNames[lowMonth - 1] << " ";
  output << lowDay << ", ";
  output << lowYear << endl;

  // close files
  input.close();
  output.close();

  return 0;
}
