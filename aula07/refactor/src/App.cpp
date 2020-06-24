#include "App.h"

#define DEBUG true

#include <string>
#include <iostream>

App::App(std::string& filename) : diary(filename)
{
  std::cout << "Abrindo/criando arquivo de saida (ex. diary.md)" << std::endl;
}

int App::run(int argc, char* argv[])
{
  if (argc == 1)
  {
    return show_usage();
  }
  std::string action = argv[1];
  if (action == "add")
  {
    if (argc == 2)
    {
      add();
    }
    else
    {
      add(argv[2]);
    }
  }
  else if (action == "list")
  {
    list_messages();
  }
  else return show_usage();
  
  return 0;
}


void App::add()
{
  std::string message;
  std::cout << "Enter your message:" << std::endl;
  std::getline(std::cin, message);
  add(message);
}

void App::add(const std::string& message)
{
  #if DEBUG
  std::cout << "Adicionando 10x a msg na array" << std::endl;
  #endif
  for (size_t i = 0; i < 15; i++)
  {
    if( !diary.add(message) ) std::cout << "Número máximo de mensagens excedido." << std::endl;
  }
  diary.write();
}

void App::list_messages()
{
  for (size_t i = 0; i < diary.messages_size; ++i)
  {
    const Message& message = diary.messages[i];
    std::cout << message.content << std::endl;
  }
}

int App::show_usage()
{
  std::cout << "TODO: USage" << std::endl;
  return 1;
}
