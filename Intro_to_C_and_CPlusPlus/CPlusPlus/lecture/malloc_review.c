#include <stdio.h>
#include <stdlib.h>

/* 1 2 3 4
   5 6 7 8
   9 12 11 12 */

int main(){
  int arr[3][4] = {1, 2, 3, 4,
                   5, 6, 7, 8,
                   9, 10, 11, 12};

  int r = 3, c = 4;

  int *arr = (int *)mallow(r * c * sizeof(int));

  int i, j, count = 0;

  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      
    }
  }
}
