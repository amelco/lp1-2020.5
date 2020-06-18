#include <iostream>
#include <string>
#include <fstream>

#define SHOW_USAGE 1
#define EXEC_ADD   2
#define EXEC_LIST  3
#define ERROR      4

#define DEBUG std::cout << "aqui" << std::endl;

/* Cabeçalho das funções */
void show_usage(const std::string& prog_name);
int  check_action(const std::string& action);
int  write_in_file(const std::string& message);


int main(int argc, char* argv[])
{
  if (argc == 1)
  {
    show_usage(argv[0]);
    return 1;
  }

  std::string action = argv[1];
  int result = check_action(action);  // retorna resultado da leitura do primeiro argumento

  // verificação de segurança
  if (result == ERROR)
  {
    std::cerr << "Erro inesperado." << std::endl;
    return 1;
  }

  // caso nenhum parametro seja dado
  if (result == SHOW_USAGE)
  {
    show_usage(argv[0]);
    return 1;
  }

  // caso apenas um parametro tenha sido dado: verifica qual é (add ou list)
  std::string message;
  if (argc == 2)
  {
    if (result == EXEC_ADD)   // armazena mensagem no arquivo
    {
      std::cout << "Informe a mensagem:" << std::endl;
      std::getline(std::cin, message);
      write_in_file(message);
      std::cout << "Mensagem Adicionada!" << std::endl;
      return 0;
    }
    if (result == EXEC_LIST)  // lista mesnagens do diario
    {
      std::ifstream input_file{"diario.txt"};
      if (!input_file.is_open())
      {
          std::cout << "Arquivo não existente ou sem permissão para leitura." << std::endl;
          return 1;
      }

      std::string line;
      int line_number = 0;
      while(!input_file.eof())
      {
        ++line_number;
        getline(input_file, line);
        if (line.size() == 0) continue;
        std::cout << line_number << ". " << line << std::endl;
      }

      input_file.close();
      return 0;
      }
  }

  // caso 2 parametros tenham sido dados: deve ser necessariamente add "mensagem"
  if (argc == 3)
  {
    if (result != EXEC_ADD)
    {
      show_usage(argv[0]);
      return 1;
    }
    message = argv[2];
    write_in_file(message);
    std::cout << "Mensagem Adicionada!" << std::endl;
    return 0;
  }

  return 0;
}


/* 
 * Implementação das funções
 */

void show_usage(const std::string& prog_name)
{
    std::cout << "Uso: "  << prog_name << " [option] <mensagem>" << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "\tadd\t\tAdiciona mensagem ao arquivo" << std::endl;
    std::cout << "\tlist\t\tLista mensagens do arquivo" << std::endl;
}

int check_action(const std::string& action)
{
  if (action == "add") return EXEC_ADD;
  if (action == "list") return EXEC_LIST;
  if (action != "add" || action != "list") return SHOW_USAGE;
  return ERROR;
}

int write_in_file(const std::string& message)
{
  std::ofstream output_file{"diario.txt", std::ios::app};
  if (!output_file.is_open()) 
  {
    std::cerr << "O arquivo não pode ser aberto." << std::endl;
    return 1;
  }
  output_file << message << std::endl;
  output_file.close();
  return 0;
}
