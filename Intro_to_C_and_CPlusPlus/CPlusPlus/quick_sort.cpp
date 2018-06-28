#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    return -value;
}

int main(){
	int i, a[100];
	
	srand(time(NULL));
	
	for(i = 0; i < 100; i++){
		a[i] = rand() % 200;
		cout << a[i] << " ";
	}
	
	return 0;
}