/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "triangle.h"

Triangle::Triangle(){}

void Triangle::setTriPoints(Point a, Point b, Point c){
  tri_points[0].setX(a.getX());
  tri_points[0].setY(a.getY());
  tri_points[1].setX(b.getX());
  tri_points[1].setY(b.getY());
  tri_points[2].setX(c.getX());
  tri_points[2].setY(c.getY());
}

int Triangle::testTriPoints(Point* testPoint){
  double a, b, c;

  a = ((tri_points[1].getY()-tri_points[2].getY())
      *(testPoint->getX()-tri_points[2].getX())
      +(tri_points[2].getX()-tri_points[1].getX())
      *(testPoint->getY()-tri_points[2].getY()))
   	  /((tri_points[1].getY()-tri_points[2].getY())
      *(tri_points[0].getX()-tri_points[2].getX())
      +(tri_points[2].getX()-tri_points[1].getX())*
      (tri_points[0].getY()-tri_points[2].getY()));

  b = ((tri_points[2].getY()-tri_points[0].getY())
      *(testPoint->getX()-tri_points[2].getX())
      +(tri_points[0].getX()-tri_points[2].getX())
      *(testPoint->getY()-tri_points[2].getY()))
   	  /((tri_points[1].getY()-tri_points[2].getY())
      *(tri_points[0].getX()-tri_points[2].getX())
      +(tri_points[2].getX()-tri_points[1].getX())
      *(tri_points[0].getY()-tri_points[2].getY()));

  c = 1 - a - b;

  if((a >= 0 && a <= 1) && (b >= 0 && b <= 1) && (c >= 0 && c <= 1)){
    return 1;
  }
  else{
    return 0;
  }
}
