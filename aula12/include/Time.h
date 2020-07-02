#ifndef TIME_H
#define TIME_H

#include <string>

struct Time
{
  unsigned int hour;
  unsigned int minute;
  unsigned int second;

  Time();
  void set_from_string(const std::string& time);
  std::string to_string();
};

#endif
