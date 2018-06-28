/*
 * Eric Paulz
 * epaulz@clemson.edu
 * CPSC 1020-001, Spring 2017
 * Programming Assignment #3
 */

#include <iostream>
#include "image.h"
#include "triangle.h"
#include "quadrilateral.h"
#include "circle.h"

using namespace std;

int main(int argc, char *argv[]){
  // open files
  ifstream input(argv[1]);
  ofstream output(argv[2]);


  // variable and object declarations
  Point tri[3], quad[4], circ_center, plane;
  Triangle triangle;
  Quadrilateral quadrilateral;
  Circle circle;
  Image img;

  int i, j, width, height, circ_radius, result;
  double x, y;
  string shape;

  // check for proper usage and that files opened successfully
  if(argc != 3){
    cout << "USAGE ERROR: <executable> <input file> <output file>";
    return 1;
  }
  if(input.fail()){
    cout << argv[1] << " did not open successfully\n";
    return 1;
  }
  if(output.fail()){
    cout << argv[2] << " did not open successfully\n";
    return 1;
  }

  // read in image width & height and set the header
  input >> width >> height;
  img.setHdr("P6", width, height, 255);

  // resize the image vector and create default background
  img.resizeVector(width, height);

  // while the file is still readable, read in data (conditionally)
  while(input >> shape){
    if(shape == "Triangle" || shape == "triangle"){
      for(i = 0; i < 3; i++){
        input >> y >> x;
        tri[i].setX(x);
        tri[i].setY(y);
      }

      triangle.setTriPoints(tri[0], tri[1], tri[2]);

      for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
          Point *temp_point = &plane;  // create a plane of points
          temp_point->setX(i);         // to test
          temp_point->setY(j);

          result = triangle.testTriPoints(temp_point);

          if(result == 1){
            img.setPxlClr(i, j, 255, 0, 0);  // if point passes the test
          }                                  // change color of that pixel
        }
      }
    }

    else if(shape == "Quadrilateral" || shape == "quadrilateral"){
      for(i = 0; i < 4; i++){
        input >> y >> x;
        quad[i].setX(x);
        quad[i].setY(y);
      }

      quadrilateral.setQuadPoints(quad[0], quad[1], quad[2], quad[3]);
      quadrilateral.setTriangles();

      for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
          Point *temp_point = &plane;  // create a plane of points
          temp_point->setX(i);         // to test
          temp_point->setY(j);

          result = quadrilateral.testTriangles(temp_point);

          if(result >= 1){
            img.setPxlClr(i, j, 127, 0, 255);  // if point passes the test
          }                                  // change color of that pixel
        }
      }
    }

    else if(shape == "Circle" || shape == "circle"){
      input >> y >> x >> circ_radius;
      circ_center.setX(x);
      circ_center.setY(y);

      circle.setCirclePoints(circ_center, circ_radius);

      for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
          Point *temp_point = &plane;  // create a plane of points
          temp_point->setX(i);         // to test
          temp_point->setY(j);

          result = circle.testCirclePoints(temp_point);

          if(result == 1){
            img.setPxlClr(i, j, 255, 255, 0);  // if point passes the test
          }                                    // change color of that pixel
        }
      }
    }
  }

  // print the image
  img.printHdr(output);
  img.printImage(output);

  // close files
  input.close();
  output.close();

  return 0;
}
