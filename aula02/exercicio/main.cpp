#include <iostream>

int verifica_parametro(char* param)
{
  if (std::string(param) != "add")
  {
    std::cout << "O primeiro parametro deve ser 'add'" << std::endl;
    return -1;
  }
  else 
  {
    return 0;
  }
}

int main(int argc, char* argv[])
{
  std::string mensagem;
  if (argc == 1) 
  {
    std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
    return -1;
  }
  if (argc == 2)
  {
    if (verifica_parametro(argv[1]) != 0) return -1;
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, mensagem);
    std::cout << "Mensagem adicionada." << std::endl;
  }
  if (argc >= 3)
  {
    if (verifica_parametro(argv[1]) != 0) return -1;
    mensagem = argv[2];
    std::cout << "Mensagem adicionada." << std::endl;
  }
  return 0;
}
