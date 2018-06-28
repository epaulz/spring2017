/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #2
 */

#include "Header.h"

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
void Header::setMax(int m){
  max = m;
}

void Header::printHeader(ofstream& output){
  output << pNum << endl;
  output << width << " " << height << " " << max << " ";
}
