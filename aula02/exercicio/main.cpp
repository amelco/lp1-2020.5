#include <iostream>

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
    if (std::string(argv[1]) != "add")
    {
      std::cout << "O primeiro parametro deve ser 'add'" << std::endl;
      return -1;
    }
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, mensagem);
  }
  if (argc == 3)
  {
    mensagem = argv[2];
  }
  std::cout << "Mensagem adicionada." << std::endl;
  return 0;
}
