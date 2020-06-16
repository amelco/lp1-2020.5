#include <iostream>

int main(int argc, char* argv[])
{
  int n1 = 0; 
  int n2 = 0;
  std::cout << "Digite um número: ";
  std::cin >> n1;
  std::cout << "Digite um outro número: ";
  std::cin >> n2;

  int sum = n1 + n2;

  std::cout << "A soma entre os dois números é: " << sum << std::endl;

  return 0;
}
