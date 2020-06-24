#include "Diary.h"

#include <string>
#include <fstream>

Diary::Diary(const std::string &_filename) : filename(_filename)
{
  // atribui message_size ao numero de linhas do arquivo, ou zero no caso de um nmovo arquivo
  std::ifstream file(filename);
  if (file.fail()) messages_size =  0;
  else
  {
    size_t num_linhas = 0;
    while (!file.eof())
    {
      std::string temp;
      std::getline(file, temp);
      num_linhas++;
    }
    messages_size = num_linhas - 1;
  }
  file.close();
  
  messages_capacity = 10;
  messages = new Message[messages_capacity];
}

Diary::~Diary()
{
  delete[] messages;
}

bool Diary::add(const std::string &message)
{
  if (messages_size >= messages_capacity) return false;
  messages[messages_size].content = message;
  messages_size++;
  return true;
}
bool Diary::write()
{
  std::ofstream file(filename, std::ios::app);
  if (file.fail()) return false;
  file << messages[messages_size -1].content << std::endl;
  file.close();
  return true;
}
