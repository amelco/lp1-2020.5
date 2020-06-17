#include <iostream>
#include <string>
#include <fstream>


void show_usage(const std::string& prog_name);

int main(int argc, char* argv[])
{
  std::ifstream input_file{"entrada.txt"};
  std::ofstream output_file{"diario.txt", std::ios::app};

  if (argc == 1)
  {
    show_usage(argv[0]);
    return 1;
  }

  std::string action = argv[1];
  
  if (action != "add")
  {
    show_usage(argv[0]);
    return 1;
  }

  std::string message;
  if (argc == 2)
  {
    std::cout << "Informe a mensagem:"   << std::endl;
    std::getline(std::cin, message);
  }
  else
  {
    message = argv[2];
  }

  output_file << message << std::endl;
  std::cout << "Mensagem Adicionada!" << std::endl;

  return 0;
}

void show_usage(const std::string& prog_name)
{
    std::cout << "Uso: "  << prog_name << " add <mensagem>" << std::endl;
}
