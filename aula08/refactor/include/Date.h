#ifndef DATE_H
#define DATE_H

#include <string>

struct Date
{
  Date();
  unsigned int year;
  unsigned int month;
  unsigned int day;

  void set_from_string(const std::string& date);
  std::string to_string();
};

#endif
