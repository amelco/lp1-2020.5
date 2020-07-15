#include "Cliente.h"
#include <sstream>

Cliente::Cliente() {}
Cliente::Cliente(std::string _nome, std::string _cpf) : nome(_nome), cpf(_cpf) {}

void Cliente::set_nome(std::string _nome) { nome = _nome; }
std::string Cliente::get_nome()           { return nome; }

void Cliente::set_cpf(std::string _cpf) { cpf = _cpf; }
std::string Cliente::get_cpf()          { return cpf; }

std::string Cliente::to_string()
{
    std::ostringstream stream;
    stream << "Nome:\t" << nome << std::endl;
    stream << "CPF:\t" << cpf << std::endl;
    return stream.str();
}