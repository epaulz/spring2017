/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #2
 */

#include "Color.h"

Color::Color(){
  red = 0;
  green = 0;
  blue = 0;
}

void Color::setRed(unsigned char r){
  red = r;
}
void Color::setGreen(unsigned char g){
  green = g;
}
void Color::setBlue(unsigned char b){
  blue = b;
}

unsigned char Color::getRed(){
  return red;
}
unsigned char Color::getGreen(){
  return green;
}
unsigned char Color::getBlue(){
  return blue;
}
