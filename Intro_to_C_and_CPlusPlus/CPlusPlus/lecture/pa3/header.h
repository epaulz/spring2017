/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <string>

using namespace std;

class Header{
  private:
    string pNum;
    int width, height, max;

  public:
    Header();
    void setPNum(string);
    void setWidth(int);
    void setHeight(int);
    int getWidth();
    int getHeight();
    void setMax(int);
    void printHeader(ofstream&);
};

#endif
