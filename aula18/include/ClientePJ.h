#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

class ClientePJ
{
  private:
    std::string razao_social;
    std::string cnpj;
  
  public:
    ClientePJ();
    ClientePJ(std::string, std::string);
    void set_razao_social(std::string);
    std::string get_razao_social();
    void set_cnpj(std::string);
    std::string get_cnpj();

    std::string to_string();
};

#endif  // CLIENTEPJ_H
