/*
 * Eric Paulz
 * epaulz@clemson.edu
 * Lab #8
 * CPSC 1021-004
 * Nick Glyder
 */

#include "Date.h"

// default constructor
Date::Date(){
  month = 0;
  day = 0;
  year = 0;
}

// overloaded constructor
Date::Date(int m, int d, int y){
  month = m;
  day = d;
  year = y;
}

// setters
void Date::setMonth(int m){
  month = m;
}
void Date::setDay(int d){
  day = d;
}
void Date::setYear(int y){
  year = y;
}

// getters
int Date::getMonth(){
  return month;
}
int Date::getDay(){
  return day;
}
int Date::getYear(){
  return year;
}
