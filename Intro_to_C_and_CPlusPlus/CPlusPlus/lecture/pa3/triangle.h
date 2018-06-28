/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "point.h"

using namespace std;

class Triangle : public Shape{
private:
  Point tri_points[3];
public:
  Triangle();
  void setTriPoints(Point, Point, Point);
  int testTriPoints(Point*);
};

#endif
