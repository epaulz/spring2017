/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "pixel.h"
#include "header.h"
#include <vector>

using namespace std;

class Image{
  private:
    Header hdr;
    vector< vector<Pixel> > pxls;
  public:
    Image();
    void setHdr(string, int, int, int);
    void resizeVector(int,int);
    void printHdr(ofstream&);
    void setPxlClr(int, int, unsigned char, unsigned char, unsigned char);
    void printImage(ofstream&);
};

#endif
