/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #2
 */

#ifndef POINT_H
#define POINT_H

class Point{
  private:
    double x, y;

  public:
    Point();
    void setX(double);
    void setY(double);
    double getX();
    double getY();
};

#endif
