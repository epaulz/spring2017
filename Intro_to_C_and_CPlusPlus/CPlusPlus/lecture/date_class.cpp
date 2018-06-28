#include <iostream>

class Date{
  private:
    int day, month, year;
  public:
    // default constructor
    Date();
    // overloaded constructor
    Date(int, int, int);
    // setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    //getters
    int getDay();
    int getMonth();
    int getYear();
};

Date::Date(){
  day = 0;
  month = 0;
  year = 0;
}
Date::Date(int d, int m, int y){
  d = 0;
  m = 0;
  y = 0;
}

void Date::setDay(int d){
  day = d;
}
void Date::setMonth(int m){
  month = m;
}
void Date::setYear(int y){
  year = y;
}
int Date::getDay(){
  return day;
}
int Date::getMonth(){
  return month;
}
int Date::getYear(){
  return year;
}

int main(){
  Date todaysDate;

  int usr_day, usr_month, usr_year;
  std::cout << "Please enter the current date (mm dd yyyy)" << std::endl;
  std::cin >> usr_month >> usr_day >> usr_year;

  todaysDate.setDay(usr_day);
  todaysDate.setMonth(usr_month);
  todaysDate.setYear(usr_year);

  int a = todaysDate.getDay();
  int b = todaysDate.getMonth();
  int c = todaysDate.getYear();

  std::cout << a << "/" << b << "/" << c << std::endl;

  return 0;
}
