/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef COLOR_H
#define COLOR_H

class Color{
private:
  unsigned char red, green, blue;

public:
  Color();
  void setRed(unsigned char);
  void setGreen(unsigned char);
  void setBlue(unsigned char);
  unsigned char getRed();
  unsigned char getGreen();
  unsigned char getBlue();
};

#endif
