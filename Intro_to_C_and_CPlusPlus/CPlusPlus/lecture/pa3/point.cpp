/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "point.h"

Point::Point(){
  x = 0;
  y = 0;
}

void Point::setX(double set_x){
  x = set_x;
}
void Point::setY(double set_y){
  y = set_y;
}

double Point::getX(){
  return x;
}
double Point::getY(){
  return y;
}
