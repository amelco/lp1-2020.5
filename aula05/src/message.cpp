#include "../include/message.h"
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> get_splitted_datetime()
{
  auto now = std::chrono::system_clock::now();
  std::time_t now_t = std::chrono::system_clock::to_time_t(now);
  std::string now_str = std::ctime(&now_t);
  std::vector<std::string> result;
  std::istringstream iss{now_str};
  for (std::string now_str; iss >> now_str; ) result.push_back(now_str);
  return result;
}

std::string Date::get_current_date()
{
  std::vector<std::string> result = get_splitted_datetime();
  return result[0] + " " +
         result[1] + " " +
         result[2] + " " + 
         result[4];
}

std::string Date::to_string()
{
  return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

std::string Time::get_current_time()
{
  std::vector<std::string> result = get_splitted_datetime();
  return result[3];
}

