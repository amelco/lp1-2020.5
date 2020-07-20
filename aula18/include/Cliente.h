#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente
{
private:
    std::string nome;
    std::string identificacao;

public:
    Cliente();
    Cliente(std::string, std::string);
    ~Cliente();

    void set_nome(std::string);
    std::string get_nome();
    void set_identificacao(std::string);
    std::string get_identificacao();
    
    std::string to_string();
};

#endif // CLIENTE_H