#include "Diary.h"

#include <string>

Diary::Diary(const std::string &_filename) : filename(_filename)
{
  messages_capacity = 10;
  messages_size = 0;
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
void Diary::write()
{
}
