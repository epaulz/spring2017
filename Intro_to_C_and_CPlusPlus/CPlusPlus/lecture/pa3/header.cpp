/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include "header.h"

Header::Header(){
  pNum = "";
  width = 0;
  height = 0;
  max = 0;
}

void Header::setPNum(string magicNum){
  pNum = magicNum;
}
void Header::setWidth(int w){
  width = w;
}
void Header::setHeight(int h){
  height = h;
}
int Header::getWidth(){
  return width;
}
int Header::getHeight(){
  return height;
}
void Header::setMax(int m){
  max = m;
}

void Header::printHeader(ofstream& output){
  output << pNum << endl;
  output << width << " " << height << " " << max << " ";
}
