#include "App.h"

#define DEBUG std::cout << "aqui" << std::endl;

#include <string>
#include <iostream>
#include <fstream>

App::App(std::string& filename) : diary(filename)
{
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
  else if (action == "search")
  {
    if (argc == 2)
    {
      search();
    }
    else
    {
      search(argv[2]);
    }
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
  if ( !diary.add(message) ) std::cerr << "Número máximo de mensagens excedido." << std::endl;
  if ( !diary.write()      ) std::cerr << "Erro na escrita do arquivo." << std::endl;
}

void App::list_messages()
{
  for (size_t i=0; i<diary.messages_size; ++i)
  {
    std::cout << diary.messages[i].date.to_string().substr(2,10) << " ";
    std::cout << diary.messages[i].time.to_string().substr(2,8) << " ";
    std::cout << diary.messages[i].content << std::endl;
  }
}

void App::search()
{
  std::string what;
  std::cout << "Enter word to search:" << std::endl;
  std::getline(std::cin, what);
  search(what);
}

void App::search(const std::string what)
{
  Message* msg = diary.search(what);
  if (msg) std::cout << msg->content << std::endl;        // verifica se o ponteiro é válido (não aponta pra null)
  else std::cout << "Texto não encontrado." << std::endl;
}


int App::show_usage()
{
  std::cout << "Usage:\tdiary [option]\nOptions:" << std::endl;
  std::cout << "\tadd [message]\tAdiciona mensagem ao diário" << std::endl;
  std::cout << "\tsearch [texto]\tPesquisa por 'texto' no diário" << std::endl;
  std::cout << "\tlist\t\tLista mensagens do diário" << std::endl;
  return 1;
}
