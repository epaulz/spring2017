/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef PIXEL_H
#define PIXEL_H

#include "color.h"
#include "point.h"
#include <fstream>

using namespace std;

class Pixel{
  private:
    Color clr;
    Point pnt;

  public:
    Pixel();
    void setColor(unsigned char, unsigned char, unsigned char);
    void printColor(ofstream&);
};

#endif
