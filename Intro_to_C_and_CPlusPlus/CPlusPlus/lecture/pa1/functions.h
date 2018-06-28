/*
 * Eric Paulz
 * CPSC 1020-001, Spring 2017
 * epaulz@clemson.edu
 * Programming Assignment #1
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures
typedef struct{
  char pNum[2];
  int width, height, colorNum;
} header_t;

typedef struct{
  unsigned char red, green, blue;
} pixel_t;

// functions prototypes
void readHeader(header_t*, FILE*);
void readImage(header_t*, pixel_t**, FILE*);
void chooseTransform(header_t*, pixel_t**, FILE*);
void printP6Image(header_t*, pixel_t **, FILE*);
void grayScaleImage(header_t *, pixel_t **, FILE*);
void flipImage(header_t *, pixel_t **, FILE*);
void rotateLeft(header_t * , pixel_t **, FILE*);
void rotateRight(header_t *, pixel_t **, FILE*);
void color2Negative(header_t*, pixel_t **, FILE*);
void reprint(header_t*, pixel_t**, FILE*);
void verticalMirror(header_t*, pixel_t**, FILE*);
void horizontalMirror(header_t*, pixel_t**, FILE*);

#endif
