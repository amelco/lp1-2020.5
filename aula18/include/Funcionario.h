#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
private:
    std::string nome;
    unsigned matricula;

public:
    Funcionario();
    Funcionario(std::string, unsigned);
    ~Funcionario();
    void set_nome(std::string);
    std::string get_nome();
    void set_matricula(unsigned);
    unsigned get_matricula();

    std::string to_string();
}

#endif // FUNCIONARIO_H