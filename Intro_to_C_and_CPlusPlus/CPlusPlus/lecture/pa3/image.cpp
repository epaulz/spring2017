/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "image.h"

Image::Image(){}

void Image::setHdr(string magicNum, int w, int h, int m){
  hdr.setPNum(magicNum);
  hdr.setWidth(w);
  hdr.setHeight(h);
  hdr.setMax(m);
}

// resize 2d vector to dimensions read in from input file
// also sets the default background pattern/color for the image
void Image::resizeVector(int x, int y){
  int i, j;
  int a, b;
  a = 0;
  b = 255;

  pxls.resize(y, vector<Pixel>(x));

  for(i = 0; i < y; i++){
    for(j = 0; j < x; j++){
      pxls.at(i).at(j).setColor(a, b, 0);
      a++;
      b--;
    }
  }
}

void Image::printHdr(ofstream& output){
  hdr.printHeader(output);
}

void Image::setPxlClr(int row, int col, unsigned char r, unsigned char g,
                      unsigned char b){
  pxls.at(row).at(col).setColor(r, g, b);
}

void Image::printImage(ofstream& output){
  int i, j;

  for(i = 0; i < hdr.getHeight(); i++){
    for(j = 0; j < hdr.getWidth(); j++){
      pxls.at(i).at(j).printColor(output);
    }
  }
}
