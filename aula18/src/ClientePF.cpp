#include "ClientePF.h"
#include <sstream>

ClientePF::ClientePF() {}
ClientePF::ClientePF(std::string _nome, std::string _cpf) : nome(_nome), cpf(_cpf) {}

void ClientePF::set_nome(std::string _nome) { nome = _nome; }
std::string ClientePF::get_nome()           { return nome; }

void ClientePF::set_cpf(std::string _cpf) { cpf = _cpf; }
std::string ClientePF::get_cpf()          { return cpf; }

std::string ClientePF::to_string()
{
    std::ostringstream stream;
    stream << "Nome:\t" << nome << std::endl;
    stream << "CPF:\t" << cpf << std::endl;
    return stream.str();
}