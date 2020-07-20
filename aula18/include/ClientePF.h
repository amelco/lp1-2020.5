#ifndef CLIENTEPF_H
#define CLIENTEPF_H

#include "Cliente.h"
#include <string>

class ClientePF : public Cliente
{
  public:
    ClientePF();
    ClientePF(std::string, std::string);

    std::string to_string();
};

#endif  // CLIENTEPJ_H
