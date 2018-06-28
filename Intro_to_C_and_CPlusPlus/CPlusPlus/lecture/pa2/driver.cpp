/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #2
 */

#include <iostream>
#include "Image.h"

using namespace std;

// client function prototype
int checkAllPoints(Point *p, Point *testPoint);

int main(int argc, char *argv[]){
  // open files
  ofstream outPut(argv[2]);
  ifstream inPut(argv[1]);

  // variable declarations
  Point triangle1[3], triangle2[3], plane;
  Image img;
  int i, j, hdrWidth, hdrHeight;
  double x1, y1, x2, y2;
  bool result1, result2;

  // check for proper usage and that files opened successfully
  if(argc != 3){
    cout << "USAGE ERROR:  ./executable outPutFileName";
    return 1;
  }
  if(inPut.fail()){
    cout << argv[1] << " did not open successfully\n";
    return 1;
  }
  if(outPut.fail()){
    cout << argv[2] << " did not open successfully\n";
    return 1;
  }

  // read in image width & height
  inPut >> hdrWidth >> hdrHeight;

  // read in points for 1st triangle
  for(i = 0; i < 3; i++){
    inPut >> y1 >> x1;
    triangle1[i].setX(x1);
    triangle1[i].setY(y1);
  }

  // read points for 2nd triangle
  for(i = 0; i < 3; i++){
    inPut >> y2 >> x2;
    triangle2[i].setX(x2);
    triangle2[i].setY(y2);
  }

  // set and print the header using instance of Image
  img.setHdr("P6", hdrWidth, hdrHeight, 255);
  img.printHdr(outPut);

  // test all points on the plane
  for(i = 0; i < hdrHeight; i++){
    for(j = 0; j < hdrWidth; j++){
      Point *temp_point = &plane;
      temp_point->setX(i);
      temp_point->setY(j);

      result1 = checkAllPoints(triangle1, temp_point);
      result2 = checkAllPoints(triangle2, temp_point);

      // print 3 colors depending on which tests are passed
      if(result1 == 1 && result2 == 1){
        img.setPxlClr(0, 255, 0); // green
        img.printPxlClr(outPut);
      }
      else if(result1 == 1){
        img.setPxlClr(234, 106, 32); // Clemson orange
        img.printPxlClr(outPut);
      }
      else{
        img.setPxlClr(82, 45, 128); // Clemson purple
        img.printPxlClr(outPut);
      }
    }
  }

  // close files
  inPut.close();
  outPut.close();

  return 0;
}

// client function to test points
int checkAllPoints(Point *p, Point *testPoint){
  double a, b, c;

  a = ((p[1].getY()-p[2].getY())*(testPoint->getX()-p[2].getX())
      +(p[2].getX()-p[1].getX())*(testPoint->getY()-p[2].getY()))
   	  /((p[1].getY()-p[2].getY())*(p[0].getX()-p[2].getX())
      +(p[2].getX()-p[1].getX())*(p[0].getY()-p[2].getY()));

  b = ((p[2].getY()-p[0].getY())*(testPoint->getX()-p[2].getX())
      +(p[0].getX()-p[2].getX())*(testPoint->getY()-p[2].getY()))
   	  /((p[1].getY()-p[2].getY())*(p[0].getX()-p[2].getX())
      +(p[2].getX()-p[1].getX())*(p[0].getY()-p[2].getY()));

  c = 1 - a - b;

  if((a >= 0 && a <= 1) && (b >= 0 && b <= 1) && (c >= 0 && c <= 1)){
    return 1;
  }
  else{
    return 0;
  }
}
