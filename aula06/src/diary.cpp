#include "../include/diary.h"
#include <fstream>
#include <iostream>

bool Diary::date_exists(Date date)
{
  std::string date_str = date.to_string();
  std::ifstream file{filename};
  std::string line;
  while (!file.eof())
  {
    getline(file, line);
    if (line == "# " + date) return true;
  }
  return false;
}

bool  Diary::write_in_file(Message msg)
{
  std::ofstream file{filename, std::ios::app};
  if (!file.is_open()) 
  {
    std::cerr << "O arquivo não pode ser aberto." << std::endl;
    return false;
  }

  std::string today = msg.date.get_current_date();
  std::string now = msg.time.get_current_time();

  if (!date_exists(today)) output_file << "\n# " << today << std::endl;
  output_file << "- " << now << " " << message << std::endl;
  output_file.close();
  return true;
}

bool Diary::add(Message msg)
{
  return false;
}
