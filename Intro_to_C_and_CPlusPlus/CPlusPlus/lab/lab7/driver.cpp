/*
 * Eric Paulz
 * epaulz@clemson.edu
 * Lab #7
 * CPSC 1021-004
 * Nick Glyder
 */

#include "Color.h"

// client function stubs
void squareImage(Color&, Color&, ofstream&);
void rectangleImage(Color&, Color&, ofstream&);

int main(int argc, char* argv[]){
  // declare and open output files
  ofstream output1, output2;
  output1.open(argv[1]);
  output2.open(argv[2]);

  // check that command was entered correctly
  if(argc != 3){
    cout << "Please enter your command in the following format: ";
    cout << "<program> <output_file_1> <output_file_2>\n";
    return 1;
  }
  // check that files opened properly
  else if(!output1.is_open()){
    cout << "Output file #1 could not be opened.\n";
    return 1;
  }
  else if(!output2.is_open()){
    cout << "Output file #2 could not be opened.\n";
    return 1;
  }

  // create object w/ default constructor and set to RED
  Color my_color;
  my_color.setRed(255);
  my_color.setGreen(0);
  my_color.setBlue(0);

  // get user's color
  int rgb[3];
  cout << "Enter a value for red (0-255): ";
  cin >> rgb[0];
  cout << "Enter a value for green (0-255): ";
  cin >> rgb[1];
  cout << "Enter a value for blue (0-255): ";
  cin >> rgb[2];

  // create object and set to user's color w/ overloaded constructor
  Color user_color(rgb[0], rgb[1], rgb[2]);

  // call client functions to print images
  squareImage(my_color, user_color, output1);
  rectangleImage(my_color, user_color, output2);

  // close files
  output1.close();
  output2.close();

  return 0;
}

// client functions (prints images in 4 quadrants)
void squareImage(Color& color1, Color& color2, ofstream& output){
  int i, j, k;

  output << "P6\n" << "250 250 255 ";
  for(i = 0; i < 250 / 2; i++){
    for(j = 0; j < 250 / 2; j++){
      output << color1.getRed();
      output << color1.getGreen();
      output << color1.getBlue();
    }
    for(k = 0; k < 250 / 2; k++){
      output << color2.getRed();
      output << color2.getGreen();
      output << color2.getBlue();
    }
  }
  for(i = 0; i < 250 / 2; i++){
    for(j = 0; j < 250 / 2; j++){
      output << color2.getRed();
      output << color2.getGreen();
      output << color2.getBlue();
    }
    for(k = 0; k < 250 / 2; k++){
      output << color1.getRed();
      output << color1.getGreen();
      output << color1.getBlue();
    }
  }
}

void rectangleImage(Color& color1, Color& color2, ofstream& output){
  int i, j, k;

  output << "P6\n" << "200 400 255 ";
  for(i = 0; i < 400 / 2; i++){
    for(j = 0; j < 200 / 2; j++){
      output << color1.getRed();
      output << color1.getGreen();
      output << color1.getBlue();
    }
    for(k = 0; k < 200 / 2; k++){
      output << color2.getRed();
      output << color2.getGreen();
      output << color2.getBlue();
    }
  }
  for(i = 0; i < 400 / 2; i++){
    for(j = 0; j < 200 / 2; j++){
      output << color2.getRed();
      output << color2.getGreen();
      output << color2.getBlue();
    }
    for(k = 0; k < 200 / 2; k++){
      output << color1.getRed();
      output << color1.getGreen();
      output << color1.getBlue();
    }
  }
}
