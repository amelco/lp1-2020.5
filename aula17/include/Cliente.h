#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente
{
  private:
    std::string nome;
    std::string cpf;
  
  public:
    Cliente();
    Cliente(std::string, std::string);
    void set_nome(std::string);
    std::string get_nome();
    void set_cpf(std::string);
    std::string get_cpf();

    std::string to_string();
};

#endif  // CLIENTEPJ_H
