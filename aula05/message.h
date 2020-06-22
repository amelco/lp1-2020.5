#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

struct Date
{
  int day;
  int month;
  int year;

  int get_current_date();
  int set_current_date();
  int compare(Date another_date); // retorna 0 se igual, -1 se menor, +1 se maior
};

struct Time
{
  int second;
  int minute;
  int hour;

  int get_current_time();
  int set_current_time();
  int compare(Time another_time); // retorna 0 se igual, -1 se menor, +1 se maior

};

struct Message 
{

  Date date;
  Time time;
  std::string content;
};

#endif  // MESSAGE_H
