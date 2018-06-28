/*
 * Eric Paulz
 * CPSC 1021-004
 * Lab #12
 * TA: Nick Glyder
 */

#include "functions.h"

int main( int argc, char* argv[] ){

    // create an input file pointer
    std::ifstream input(argv[1]);

    // Using the command line arguments check for a valid input file
    // If there is not one, give the user a message and exit the program
    if(argc != 2){
        std::cout << "Usage error: <executable> <input file>\n";
        return 1;
    }
    if(input.fail()){
        std::cout << argv[1] << " could not be opened.\n";
        return 1;
    }

    // create a vector to store items from input file
    std::vector<int> list;

    // read input file and populate vector
    int curr_item;
    while(input >> curr_item){
        list.push_back(curr_item);
    }

    // close input file
    input.close();

    // print unsorted list
    std::cout << "UNSORTED LIST: ";
    print_vector(list);

    // sort vector using quickSort function
    int start_index = 0;
    int end_index = list.size() - 1;

    quickSort(list, start_index, end_index);

    // print sorted list
    std::cout << "SORTED LIST: ";
    print_vector(list);

    // ask for user input
    int usr_num;
    std::cout << "Enter a number: ";
    std::cin >> usr_num;

    // use binarySearch function to check list for user's number
    int found = binarySearch(list, start_index, end_index, usr_num);

    if(found == usr_num){
      std::cout << "Your number (" << usr_num;
      std::cout << ") was FOUND in the list! :D\n";
    }
    else /*if(found == -usr_num)*/{
      std::cout << "Your number (" << usr_num;
      std::cout << ") was NOT FOUND in the list. :'(\n";
    }

    return 0;
}
