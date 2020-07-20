#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include "Cliente.h"
#include <string>

class ClientePJ : public Cliente
{
  public:
    ClientePJ();
    ClientePJ(std::string, std::string);
    
    std::string to_string();
};

#endif  // CLIENTEPJ_H
