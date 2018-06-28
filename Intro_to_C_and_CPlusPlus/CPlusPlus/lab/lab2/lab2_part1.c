/* Eric Paulz
 * epaulz@clemson.edu
 * Lab 2 (Part 1)
 * Section 004
 * Nick Glyder
 */

#include <stdio.h>

int main(int argc, char *argv[]){
  FILE *input;
  FILE *output;
  char magic_num[2];
  int header[3];
  char pixels[1000000];
  int i;

// Open input & output files
  input = fopen(argv[1], "r");
  output = fopen(argv[2], "w");

// Make sure that the files were opened correctly
  if(argc != 3){
    printf("**Need an input and output file\n");
    return 1;
  }
  if(input == NULL){
    printf("**File did not open correctly\n");
    return 1;
  }
  if(output == NULL){
    printf("**File did not open correctly\n");
    return 1;
  }

// Read .ppm header from input and copy it to output
  fscanf(input, "%s %d%d%d ", magic_num, &header[0], &header[1], &header[2]);
  fprintf(output, "%s\n%d %d %d\n", magic_num, header[0], header[1], header[2]);

// Read pixel data from input and copy it to output
  for(i = 0; i < ((header[0] * header[1])*3); i++){
    fscanf(input, "%c ", &pixels[i]);
  }

  for(i = 0; i < ((header[0] * header[1])*3); i++){
    fprintf(output, "%c", pixels[i]);
  }

  return 0;
}
