#include "MyArray.h"

/*These are two client (helper) functions that you may use */
int MyArrayLength(const char* str)
{
  //cout << "MyArrayLength\n";
  int len = 0;
  const char* s = str;
  while( *s != '\0')
  {
    len++;
    s++;
  }
  return len;
}

void MyArrayCopy(char* dest, const char* src, int n)
{
  //cout << "MyArrayCopy\n";
  int i;
  for(i = 0; i < n; i++)
  {
    dest[i] = src[i];
  }
}

/*Implement the class functions here. */
// default constructor
MyArray::MyArray(){std::cout << "Default constructor.\n";}

// regular constructor
MyArray::MyArray(const char* string){
  std::cout << "Regular constructor.\n";
  ptr = string;
}

// copy constructor
MyArray::MyArray(const MyArray& array){
  std::cout << "Copy Constructor.\n";

  size = new int;
  *size = *array.size;

  ptr = new char;
  *ptr = *array.ptr;
}

int MyArray::getSize(){
  return size;
}

MyArray::~MyArray(){
  std::cout << "Destructor.\n";
  delete ptr;
}


// assignment operator overloader
const MyArray& MyArray::operator=(const MyArray &something){
  if(this == &something){
    return *this;
  }
  size = something.
}
