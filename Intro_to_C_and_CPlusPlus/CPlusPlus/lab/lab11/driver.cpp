/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1021-004
 * Lab 11
 * Nick Glyder
 */

#include <vector>
#include <fstream>
#include <cstdlib>
#include "functions.h"

int main(int argc, char* argv[]){
  // open input file
  std::ifstream input(argv[1]);

  // check for proper usage and that file opened
  if(argc != 2){
	  std::cout << "Usage error: <executable> <input file>\n";
	  return 1;
  }
  if(input.fail()){
	  std::cout << argv[1] << " could not be opened.\n";
	  return 1;
  }

  // create a vector to store data (since we don't know # of items)
  std::vector<int> vector_items;

  // read in data and populate vector
  int temp;
  while(input >> temp){
    vector_items.push_back(temp);
  }
  
  // determine size of vector
  int num_items = vector_items.size();

  // create an array and copy the vector into it
  int array_items[num_items];
  std::copy(vector_items.begin(), vector_items.end(), array_items);

  // close input file
  input.close();

  // print data
  std::cout << "ORIGINAL DATA: ";
  print_array(array_items, num_items);

  // sort data
  selection_sort(array_items, num_items);

  // print sorted data
  std::cout << "SORTED DATA: ";
  print_array(array_items, num_items);

  // ask user for a number
  int usr_num;
  std::cout << "\nEnter search item: ";
  std::cin >> usr_num;

  // search data for user's number
  int index;

  // if number is found, function will return its index
  index = linear_search(array_items, num_items, usr_num);

  // tell user if their number was found, and if so, at what index
  if(index){
    std::cout << usr_num << " found at index " << (index-1) << "." << std::endl;
  }
  else{
    std::cout << usr_num << " not found in the data.\n";
  }

  return 0;
}
