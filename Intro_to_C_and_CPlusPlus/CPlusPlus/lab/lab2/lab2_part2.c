/* Eric Paulz
 * epaulz@clemson.edu
 * Lab 2 (Part 2)
 * Section 004
 * Nick Glyder
 */

#include <stdio.h>

int main(){
  char r_array[3] = {0, 255, 255};
  char g_array[3] = {0, 0, 255};
  char b_array[3] = {0, 0, 0};

  char magic_num[2] = {'P', '6'};
  int width = 600;
  int height = 399;
  int max_val = 255;
  int i;

// Print header
  fprintf(stdout, "%s\n%d %d %d\n", magic_num, width, height, max_val);

// Enter pixel data to create German flag
  for(i = 0; i < (width * (height / 3)); i++){
    fprintf(stdout, "%c%c%c", r_array[0], g_array[0], b_array[0]);
  }
  for(i = 0; i < (width * (height /3)); i++){
    fprintf(stdout, "%c%c%c", r_array[1], g_array[1], b_array[1]);
  }
  for(i = 0; i < (width * (height /3)); i++){
    fprintf(stdout, "%c%c%c", r_array[2], g_array[2], b_array[2]);
  }

  return 0;
}
