/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1021-004
 * Lab 11
 * Nick Glyder
 */

#include "functions.h"

void print_array(int array[], int array_size){
  int i;
  for(i = 0; i < array_size; i++){
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void selection_sort(int array[], int array_size){
  int i, j, small, temp;
  
  // sorting algorithm
  for(i = 0; i < array_size - 1; i++){
    small = i;

    for(j = i+1; j < array_size; j++){
      if(array[j] < array[small]){
        small = j;
      }
    }

    if(small != i){
      temp = array[i];
      array[i] = array[small];
      array[small] = temp;
    }
  }
}

int linear_search(int array[], int array_size, int search_item){
  int i;
  for(i = 0; i < array_size; i++){
    if(array[i] == search_item){
      return i+1; // if number is found, return its index
    }
  }
  return 0; // if not found, return 0
}
