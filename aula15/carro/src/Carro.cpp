#include "Carro.h"
#include <sstream>

int Carro::num_carros = 0;

Carro::Carro()
{
  this->cor = "Branco";
  this->num_portas = 2;
  this->velocidade = 0.0f;
  this->num_carros++;
}

Carro::~Carro()
{
}

void Carro::acelera(int quantidade)
{
  this->velocidade += quantidade;
}

void Carro::freia(int quantidade)
{
  if (this->velocidade > 0.0f) this->velocidade -= quantidade;
}

std::string Carro::to_string()
{
  std::ostringstream saida;
  saida << "Cor:\t\t" << this->cor << std::endl;
  saida << "# Portas:\t" << this->num_portas << std::endl;
  saida << "Velocidade:\t" << this->velocidade << " km/h" << std::endl;
  saida << "Total carros:\t" << this->num_carros << std::endl;
  return saida.str();
}
