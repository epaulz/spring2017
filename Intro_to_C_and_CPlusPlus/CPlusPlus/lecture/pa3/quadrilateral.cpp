/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "quadrilateral.h"

Quadrilateral::Quadrilateral(){}

void Quadrilateral::setQuadPoints(Point a, Point b, Point c, Point d){
  quad_points[0].setX(a.getX());
  quad_points[0].setY(a.getY());
  quad_points[1].setX(b.getX());
  quad_points[1].setY(b.getY());
  quad_points[2].setX(c.getX());
  quad_points[2].setY(c.getY());
  quad_points[3].setX(d.getX());
  quad_points[3].setY(d.getY());
}


void Quadrilateral::setTriangles(){
  tri1.setTriPoints(quad_points[0], quad_points[1], quad_points[2]);
  tri2.setTriPoints(quad_points[1], quad_points[2], quad_points[3]);
  tri3.setTriPoints(quad_points[2], quad_points[3], quad_points[0]);
}


int Quadrilateral::testTriangles(Point* testPoint){
  int a, b, c;

  a = tri1.testTriPoints(testPoint);
  b = tri2.testTriPoints(testPoint);
  c = tri3.testTriPoints(testPoint);

  return a + b + c;
}
