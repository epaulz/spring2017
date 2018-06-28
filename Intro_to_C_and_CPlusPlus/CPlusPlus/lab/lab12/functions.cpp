/*
 * Eric Paulz
 * CPSC 1021-004
 * Lab #12
 * TA: Nick Glyder
 */

#include "functions.h"

/*********************************************
 *This function should print each element in *
 *the array.                                 *
 *********************************************/
void print_vector(std::vector<int> vec){
    unsigned int i;

    for(i = 0; i < vec.size(); i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

//************************************************
// quickSort uses the quickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
// This is a recursive algorithm                 *
//************************************************
void quickSort(std::vector<int>& vec, int start, int end){
    if(start >= end){
        return;
    }
    else{
        int x = partition(vec, start, end);

        quickSort(vec, start, x-1);
        quickSort(vec, x+1, end);
    }
}

//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(std::vector<int>& vec, int start, int end){

    int pivot = start;
    int i = start + 1;

    while(i <= end){
        if(vec.at(i) < vec.at(pivot) && vec.at(i) == vec.at(pivot+1)){
            std::swap(vec.at(i), vec.at(pivot));
            pivot++;
        }
        else if(vec.at(i) < vec.at(pivot) && vec.at(i) != vec.at(pivot+1)){
            std::swap(vec.at(i), vec.at(pivot+1));
            std::swap(vec.at(pivot), vec.at(pivot+1));
            pivot++;
        }
        i++;
    }
    return pivot;
}

//**********************************************************
// The binarySearch function performs a recursive binary   *
// search on a range of elements of an integer array. The  *
// parameter first holds the subscript of the range's      *
// starting element, and last holds the subscript of the   *
// ranges's last element. The parameter value holds the    *
// the search value. If the search value is found, its     *
// array subscript is returned. Otherwise, -1 is returned  *
// indicating the value was not in the array.              *
//**********************************************************
int binarySearch(std::vector<int> vec, int first, int last, int value){

    if(first <= last){
        int mid = (first + last) / 2;

        if(value == vec.at(mid)){
            return value; // found it
        }
        else if(value < vec.at(mid)){
            return binarySearch(vec, first, mid - 1, value);
        }
        else if(value > vec.at(mid)){
            return binarySearch(vec, mid + 1, last, value);
        }
    }
    return -(value+1);
}
