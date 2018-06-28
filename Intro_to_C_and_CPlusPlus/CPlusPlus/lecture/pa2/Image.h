/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #2
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include "Header.h"

class Image{
  private:
    Pixel pxl;
    Header hdr;

  public:
    void setHdr(string, int, int, int);
    void printHdr(ofstream&);
    void setPxlClr(unsigned char, unsigned char, unsigned char);
    void printPxlClr(ofstream&);
};

#endif
