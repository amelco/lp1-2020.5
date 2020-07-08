#include <iostream>

#include "Carro.h"

int main(int argc, char* argv[])
{
  Carro c1;
  std::cout << "Carro 1" << std::endl;
  std::cout << c1.to_string() << std::endl;

  Carro c2;
  std::cout << "Carro 1" << std::endl;
  std::cout << c1.to_string() << std::endl;
  std::cout << "Carro 2" << std::endl;
  std::cout << c2.to_string()<< std::endl;

  c1.acelera(10);
  c2.acelera(20);

  std::cout << "Carro 1" << std::endl;
  std::cout << c1.to_string() << std::endl;
  std::cout << "Carro 2" << std::endl;
  std::cout << c2.to_string()<< std::endl;

  return 0;
}
