#include "ClientePJ.h"
#include <sstream>

ClientePJ::ClientePJ() {}
ClientePJ::ClientePJ(std::string _razao_social, std::string _cnpj)
{
    set_nome(_razao_social);
    set_identificacao(_cnpj);
}

std::string ClientePJ::to_string()
{
    std::ostringstream stream;
    stream << "Razão social:\t" << get_nome() << std::endl;
    stream << "CNPJ:\t" << get_identificacao() << std::endl;
    return stream.str();
}