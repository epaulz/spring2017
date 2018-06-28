/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */
 
#include "circle.h"

Circle::Circle(){}

void Circle::setCirclePoints(Point c, int r){
  center = c;
  radius = r;
}

// FORMULA: (x - center_x)^2 + (y - center_y)^2 < radius^2
int Circle::testCirclePoints(Point* test_point){
  double a;

  a = ((test_point->getX()-center.getX())*(test_point->getX()-center.getX()))+
      ((test_point->getY()-center.getY())*(test_point->getY()-center.getY()));

  if(a <= (radius*radius)){
    return 1;
  }
  else{
    return 0;
  }
}
