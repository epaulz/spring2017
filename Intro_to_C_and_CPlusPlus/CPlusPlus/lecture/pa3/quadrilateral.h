/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "shape.h"
#include "point.h"
#include "triangle.h"

using namespace std;

class Quadrilateral : public Shape{
private:
  Point quad_points[4];
  Triangle tri1, tri2, tri3;
public:
  Quadrilateral();
  void setQuadPoints(Point, Point, Point, Point);
  void setTriangles();
  int testTriangles(Point*);
};

#endif
