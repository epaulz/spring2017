/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <fstream>
#include "pixel.h"

class Shape{
protected:
  Pixel shape_pxl;
public:
  Shape();
  void setShapeClr(unsigned char, unsigned char, unsigned char);
  void printShapeClr(ofstream&);
};

#endif
