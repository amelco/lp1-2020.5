#include <iostream>

int main(int argc, char* argv[])
{
  std::string nome;
  //  std::cout << "Informe seu nome: " << std::endl;
  //  std::cin >> nome;
  //  std::cout << "Olá, " << nome << std::endl;

  std::cout << "Informe seu nome: " << std::endl;
  std::getline(std::cin, nome);
  std::cout << "Olá, " << nome << std::endl;

  return 0;
}
