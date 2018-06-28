/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "shape.h"

Shape::Shape(){}

void Shape::setShapeClr(unsigned char r, unsigned char g, unsigned char b){
  shape_pxl.setColor(r, g, b);
}

void Shape::printShapeClr(ofstream& output){
  shape_pxl.printColor(output);
}
