/*
 * Eric Paulz
 * CPSC 1020-001, Spring 2017
 * epaulz@clemson.edu
 * Programming Assignment #1
 */

#include "functions.h"

// reads in header information
void readHeader(header_t* func_header, FILE* input){
  fscanf(input, "%s %d%d%d ", func_header->pNum, &func_header->width, &func_header->height, &func_header->colorNum);

  return;
}

// reads in pixel data
void readImage(header_t* func_header, pixel_t** pixel_vals, FILE* input){
  int i, j;

  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      fscanf(input, "%c%c%c", &pixel_vals[i][j].red, &pixel_vals[i][j].green, &pixel_vals[i][j].blue);
    }
  }

  return;
}

// print out new image (header & pixels)
void printP6Image(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j;

  fprintf(output, "%s\n%d %d %d ", func_header->pNum, func_header->width, func_header->height, func_header->colorNum);

  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      fprintf(output, "%c%c%c", pixel_vals[i][j].red, pixel_vals[i][j].green, pixel_vals[i][j].blue);
    }
  }

  return;
}

// print out a gray-scale image
void grayScaleImage(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j;
  unsigned char gray;

  unsigned char** output_arr = (unsigned char**)malloc(func_header->height * sizeof(unsigned char*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (unsigned char*)malloc(func_header->width * sizeof(unsigned char));
    }

  // set gray value for each pixel
  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      gray = (pixel_vals[i][j].red * .299) + (pixel_vals[i][j].green * .587) + (pixel_vals[i][j].blue * .114);
      output_arr[i][j] = gray;
    }
  }

  // change magic number to 'P5', but keep other header info the same
  strcpy(func_header->pNum, "P5");
  fprintf(output, "%s\n %d %d %d ", func_header->pNum, func_header->width, func_header->height, func_header->colorNum);

  // populate new array with gray values
  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      fprintf(output, "%c", output_arr[i][j]);
    }
  }

  free(output_arr);

  return;
}

// prints out a negative
void color2Negative(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j;

  pixel_t** output_arr = (pixel_t**)malloc(func_header->height * sizeof(pixel_t*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (pixel_t*)malloc(func_header->width * sizeof(pixel_t));
    }

  // switch all colors to their opposites
  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      output_arr[i][j].red = (255 - pixel_vals[i][j].red);
      output_arr[i][j].green = (255 - pixel_vals[i][j].green);
      output_arr[i][j].blue = (255 - pixel_vals[i][j].blue);
    }
  }

  printP6Image(func_header, output_arr, output);

  return;
}

// flips the image
void flipImage(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j;

  pixel_t** output_arr = (pixel_t**)malloc(func_header->height * sizeof(pixel_t*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (pixel_t*)malloc(func_header->width * sizeof(pixel_t));
    }

  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      output_arr[i][j].red = pixel_vals[func_header->height - (i+1)][j].red;
      output_arr[i][j].green = pixel_vals[func_header->height - (i+1)][j].green;
      output_arr[i][j].blue = pixel_vals[func_header->height - (i+1)][j].blue;
    }
  }

  printP6Image(func_header, output_arr, output);

  free(output_arr);

  return;
}

// rotates the image clockwise
void rotateRight(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j, x;

  // switch width and height
  x = func_header->width;
  func_header->width = func_header->height;
  func_header->height = x;

  pixel_t** output_arr = (pixel_t**)malloc(func_header->height * sizeof(pixel_t*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (pixel_t*)malloc(func_header->width * sizeof(pixel_t));
    }

  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      output_arr[i][j].red = pixel_vals[func_header->width - (j+1)][i].red;
      output_arr[i][j].green = pixel_vals[func_header->width - (j+1)][i].green;
      output_arr[i][j].blue = pixel_vals[func_header->width - (j+1)][i].blue;
    }
  }

  printP6Image(func_header, output_arr, output);

  free(output_arr);

  return;
}

// rotates the image counterclockwise
void rotateLeft(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j, temp;

  // switch width and height
  temp = func_header->width;
  func_header->width = func_header->height;
  func_header->height = temp;

  pixel_t** output_arr = (pixel_t**)malloc(func_header->height * sizeof(pixel_t*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (pixel_t*)malloc(func_header->width * sizeof(pixel_t));
    }

  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < func_header->width; j++){
      output_arr[i][j].red = pixel_vals[j][func_header->height - (i+1)].red;
      output_arr[i][j].green = pixel_vals[j][func_header->height - (i+1)].green;
      output_arr[i][j].blue = pixel_vals[j][func_header->height - (i+1)].blue;
    }
  }

  printP6Image(func_header, output_arr, output);

  free(output_arr);

  return;
}

// prints original image
void reprint(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  printP6Image(func_header, pixel_vals, output);

  return;
}

// EXTRA CREDIT: mirrors the image across the y-axis
void verticalMirror(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j;

  pixel_t** output_arr = (pixel_t**)malloc(func_header->height * sizeof(pixel_t*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (pixel_t*)malloc(func_header->width * sizeof(pixel_t));
    }

  // populate left half of the array
  for(i = 0; i < func_header->height; i++){
    for(j = 0; j < (func_header->width) / 2; j++){
      output_arr[i][j].red = pixel_vals[i][j].red;
      output_arr[i][j].green = pixel_vals[i][j].green;
      output_arr[i][j].blue = pixel_vals[i][j].blue;
    }
  }

  // populate right half of the array
  for(i = 0; i < func_header->height; i++){
    for(j = 0; j <= (func_header->width) / 2; j++){
      output_arr[i][func_header->width - (j+1)].red = pixel_vals[i][j].red;
      output_arr[i][func_header->width - (j+1)].green = pixel_vals[i][j].green;
      output_arr[i][func_header->width - (j+1)].blue = pixel_vals[i][j].blue;
    }
  }

  printP6Image(func_header, output_arr, output);

  free(output_arr);

  return;
}

// EXTRA CREDIT: mirrors the image across the x-axis
void horizontalMirror(header_t* func_header, pixel_t** pixel_vals, FILE* output){
  int i, j;

  pixel_t** output_arr = (pixel_t**)malloc(func_header->height * sizeof(pixel_t*));
    for(i = 0; i < func_header->height; i++){
      output_arr[i] = (pixel_t*)malloc(func_header->width * sizeof(pixel_t));
    }

  // populate top half of the array
  for(i = 0; i < (func_header->height) / 2; i++){
    for(j = 0; j < func_header->width; j++){
      output_arr[i][j].red = pixel_vals[i][j].red;
      output_arr[i][j].green = pixel_vals[i][j].green;
      output_arr[i][j].blue = pixel_vals[i][j].blue;
    }
  }

  // populate bottom half of the array
  for(i = 0; i <= (func_header->height) / 2; i++){
    for(j = 0; j < func_header->width; j++){
      output_arr[func_header->height - (i+1)][j].red = pixel_vals[i][j].red;
      output_arr[func_header->height - (i+1)][j].green = pixel_vals[i][j].green;
      output_arr[func_header->height - (i+1)][j].blue = pixel_vals[i][j].blue;
    }
  }

  printP6Image(func_header, output_arr, output);

  free(output_arr);

  return;
}

// lets user choose which transformation to perform
void chooseTransform(header_t* ct_header, pixel_t** ct_pixels, FILE* new_image){
  int user_input;
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("Thank you for using the Image Transformer!\n");
  printf("There are several transformations you can perform on the input image.\n");
  printf("Choose the number that corresponds to the transformation you wish to perform on the image:\n");
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("1.\tGray Scale\n");
  printf("2.\tColor to Negative\n");
  printf("3.\tFlip the Image\n");
  printf("4.\tRotate Right\n");
  printf("5.\tRotate Left\n");
  printf("6.\tReprint\n");
  printf("7.\tVertical Mirror\n");
  printf("8.\tHorizontal Mirror\n");
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("\nEnter a number: ");
  scanf("%d", &user_input);

  while(user_input != 1 && user_input != 2 && user_input != 3 && user_input != 4 &&
        user_input != 5 && user_input != 6 && user_input != 7 && user_input != 8){
      printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
      printf("You entered an incorrect number.  Please choose the number that\n");
      printf("corresponds to the transformation you wish to perform on the image:\n");
      printf("1.\tGray Scale\n");
      printf("2.\tColor to Negative\n");
      printf("3.\tFlip the Image\n");
      printf("4.\tRotate Right\n");
      printf("5.\tRotate Left\n");
      printf("6.\tReprint\n");
      printf("7.\tVertical Mirror\n");
      printf("8.\tHorizontal Mirror\n");
      printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
      printf("\nEnter a number: ");
      scanf("%d", &user_input);
    }

  if(user_input == 1){
    grayScaleImage(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 2){
    color2Negative(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 3){
    flipImage(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 4){
    rotateRight(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 5){
    rotateLeft(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 6){
    reprint(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 7){
    verticalMirror(ct_header, ct_pixels, new_image);
  }

  else if(user_input == 8){
    horizontalMirror(ct_header, ct_pixels, new_image);
  }

  printf("\n*** Transformation complete! ***\n");

  return;
}
