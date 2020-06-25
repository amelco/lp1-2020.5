#include "Diary.h"
#include "Utils.h"

#include <string>
#include <fstream>

Diary::Diary(const std::string &_filename) : filename(_filename),
                                             messages(nullptr),
                                             messages_size(0),
                                             messages_capacity(10)
{
  messages = new Message[messages_capacity];
  // atribui message_size ao numero de linhas do arquivo, ou zero no caso de um nmovo arquivo
  std::ifstream file(filename);
  if (file.is_open())
  {
    size_t num_linhas = 0;
    while (!file.eof())
    {
      std::string temp;
      std::getline(file, temp);
      if (num_linhas < messages_capacity) num_linhas++;
    }
    messages_size = num_linhas - 1;
  }
  file.close();
}

Diary::~Diary()
{
  delete[] messages;
}

bool Diary::add(const std::string &message)
{
  if (messages_size >= messages_capacity) return false;
  Message msg;
  Utils utils;
  msg.content = message;
  // msg.date.set_from_string(utils.get_current_date());
  // msg.time.set_from_string(utils.get_current_time());
  messages[messages_size] = msg;
  messages_size++;
  return true;
}

bool Diary::write()
{
  std::ofstream file(filename, std::ios::app);
  if (file.fail()) return false;
  // file << messages[messages_size].time.to_string() << " " << messages[messages_size - 1].content << std::endl;
  file << messages[messages_size - 1].content << std::endl;
  file.close();
  return true;
}
