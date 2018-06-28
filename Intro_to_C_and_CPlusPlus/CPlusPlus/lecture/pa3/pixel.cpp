/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "pixel.h"

Pixel::Pixel(){}

void Pixel::setColor(unsigned char r, unsigned char g, unsigned char b){
  clr.setRed(r);
  clr.setGreen(g);
  clr.setBlue(b);
}


void Pixel::printColor(ofstream& output){
  output << clr.getRed() << clr.getGreen() << clr.getBlue();
}
