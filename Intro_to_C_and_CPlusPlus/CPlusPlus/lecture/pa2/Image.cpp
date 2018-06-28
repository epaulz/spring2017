/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #2
 */

#include "Image.h"

void Image::setHdr(string magicNum, int w, int h, int m){
  hdr.setPNum(magicNum);
  hdr.setWidth(w);
  hdr.setHeight(h);
  hdr.setMax(m);
}
void Image::printHdr(ofstream& output){
  hdr.printHeader(output);
}

void Image::setPxlClr(unsigned char r, unsigned char g, unsigned char b){
  pxl.setColor(r, g, b);
}
void Image::printPxlClr(ofstream& output){
  pxl.printColor(output);
}
