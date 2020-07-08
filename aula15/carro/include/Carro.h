#ifndef CARRO_H
#define CARRO_H

#include <string>

class Carro
{
  public:
    Carro();
    ~Carro();
    
    static int num_carros;

    std::string cor;
    int num_portas;
    double velocidade;

    void acelera(int quantidade);
    void freia(int quantidade);

    std::string to_string();

};

#endif   // CARRO_H
