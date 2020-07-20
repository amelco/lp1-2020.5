#include "ClientePF.h"
#include <sstream>

ClientePF::ClientePF() {}
ClientePF::ClientePF(std::string _nome, std::string _cpf)
{
    set_nome(_nome);
    set_identificacao(_cpf);
}

std::string ClientePF::to_string()
{
    std::ostringstream stream;
    stream << "Nome:\t" << get_nome() << std::endl;
    stream << "CPF:\t" << get_identificacao() << std::endl;
    return stream.str();
}