/*
 * Eric Paulz
 * CPSC 1020-001, Spring 2017
 * epaulz@clemson.edu
 * Programming Assignment #1
 */

#include "functions.h"

int main(int argc, char *argv[]){
  FILE *f_in, *f_out;
  header_t header;
  int i;

  // check for corrent amount of arguments
  if(argc != 3){
    printf("Please enter your command using the following format: ");
    printf("<program> <input_file> <output_file>\n");
    return 1;
  }

  // open files
  f_in = fopen(argv[1], "r");
  f_out = fopen(argv[2], "w");

  // check that files opened correctly
  if(f_in == NULL){
    printf("Unable to open input file <%s>\n", argv[1]);
    return 1;
  }
  else if(f_out == NULL){
    printf("Unable to open output file <%s>\n", argv[2]);
    return 1;
  }

  // read in header information
  header_t *header_ptr = &header;
  readHeader(header_ptr, f_in);

  // allocate memory for pixel data
  pixel_t **pixels = (pixel_t**)malloc(header.height * sizeof(pixel_t*));
    for(i = 0; i < header.height; i++){
      pixels[i] = (pixel_t*)malloc(header.width * sizeof(pixel_t));
    }

  // read in pixel data
  readImage(header_ptr, pixels, f_in);

  // call function that will perform transformations
  chooseTransform(header_ptr, pixels, f_out);

  // free up memory and close files
  free(pixels);
  fclose(f_in);
  fclose(f_out);

  return 0;
}
