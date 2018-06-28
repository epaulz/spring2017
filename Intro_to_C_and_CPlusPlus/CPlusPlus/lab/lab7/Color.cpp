/*
 * Eric Paulz
 * epaulz@clemson.edu
 * Lab #7
 * CPSC 1021-004
 * Nick Glyder
 */

#include "Color.h"

// overloaded constructor
Color::Color(unsigned char r, unsigned char g, unsigned char b){
  red = r;
  green = g;
  blue = b;
}
// default constructor
Color::Color(){
  red = 0;
  green = 0;
  blue = 0;
}

// setters
void Color::setRed(unsigned char r){
  red = r;
}
void Color::setGreen(unsigned char g){
  green = g;
}
void Color::setBlue(unsigned char b){
  blue = b;
}

// getters
unsigned char Color::getRed(){
  return red;
}
unsigned char Color::getGreen(){
  return green;
}
unsigned char Color::getBlue(){
  return blue;
}
