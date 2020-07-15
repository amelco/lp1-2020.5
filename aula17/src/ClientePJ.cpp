#include "ClientePJ.h"
#include <sstream>

ClientePJ::ClientePJ() {}
ClientePJ::ClientePJ(std::string _razao_social, std::string _cnpj) : razao_social(_razao_social), cnpj(_cnpj) {}

void ClientePJ::set_razao_social(std::string _razao_social) { razao_social = _razao_social; }
std::string ClientePJ::get_razao_social()                   { return razao_social; }

void ClientePJ::set_cnpj(std::string _cnpj) { cnpj = _cnpj; }
std::string ClientePJ::get_cnpj()           { return cnpj; }

std::string ClientePJ::to_string()
{
    std::ostringstream stream;
    stream << "Razão social:\t" << razao_social << std::endl;
    stream << "CNPJ:\t" << cnpj << std::endl;
    return stream.str();
}