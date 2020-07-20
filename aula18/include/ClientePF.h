#ifndef CLIENTEPF_H
#define CLIENTEPF_H

#include <string>

class ClientePF
{
  private:
    std::string nome;
    std::string cpf;
  
  public:
    ClientePF();
    ClientePF(std::string, std::string);
    void set_nome(std::string);
    std::string get_nome();
    void set_cpf(std::string);
    std::string get_cpf();

    std::string to_string();
};

#endif  // CLIENTEPJ_H
