#include "App.h"

#define DEBUG std::cout << "aqui" << std::endl;

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
  else if (action == "interactive")
  {
    interactive_mode();
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
  for (size_t i=0; i<diary.messages.size(); ++i)
  {
    std::cout << diary.formated_message(diary.messages[i]) << std::endl;
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
  std::vector<Message*> msg = diary.search(what);

  if (msg.size() == 0)
  {
    std::cout << "Texto não encontrado." << std::endl;
    return;
  }

  for (size_t i=0; i<msg.size(); ++i)
  {
    std::cout << diary.formated_message(*msg[i]) << std::endl;
  }
}

void App::interactive_mode()
{
  char op;

  std::string home_screen = "Diário 0.1\n\n\n";
  home_screen += "Selecione uma opção:\n\n";
  home_screen += "1) Listar mensagens\n";
  home_screen += "2) Adicionar nova mensagem\n\n";
  home_screen += "0) Finalizar\n\n";
  home_screen += "Opção: ";
  
  while (op != '0')
  {
    std::cout << home_screen;
    std::cin >> op;
    std::cin.ignore(1);   // lê somente um char e limpa buffer

    if (op == '1')
    {
      std::cout << std::endl;
      list_messages();
      std::cout << "\nPressione Enter para continuar..." << std::endl;
      std::cin.ignore();
    }
    else if (op == '2') add();
  }
  std::cout << "\nAté breve.\n" << std::endl;
}

int App::show_usage()
{
  std::cout << "Usage:\tdiary [option]\nOptions:" << std::endl;
  std::cout << "\tadd [message]\tAdiciona mensagem ao diário" << std::endl;
  std::cout << "\tsearch [texto]\tPesquisa por 'texto' no diário" << std::endl;
  std::cout << "\tlist\t\tLista mensagens do diário" << std::endl;
  return 1;
}
