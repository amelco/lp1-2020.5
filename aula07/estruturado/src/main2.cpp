#include "../include/message.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Message msg;

  std::cout << msg.content << std::endl;
  std::cout << msg.date.get_current_date() << std::endl;
  std::cout << msg.time.get_current_time() << std::endl;

  return 0;
}
