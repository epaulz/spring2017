/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"

using namespace std;

class Circle : public Shape{
private:
  Point center;
  int radius;
public:
  Circle();
  void setCirclePoints(Point, int);
  int testCirclePoints(Point*);
};

#endif
