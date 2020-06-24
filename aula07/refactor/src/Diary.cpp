#include "Diary.h"

#define DEBUG true
#if DEBUG
  #include <iostream>
#endif

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
  #if DEBUG
  std::cout << messages[messages_size-1].content << ": " << messages_size << std::endl;
  #endif
  return true;
}
void Diary::write()
{
  
}
