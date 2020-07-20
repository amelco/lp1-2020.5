#include "Cliente.h"

Cliente::Cliente() {}
Cliente::Cliente(std::string _nome, std::string _identificacao) : nome(_nome), identificacao(_identificacao) {}
Cliente::~Cliente() {}

void Cliente::set_nome(std::string _nome)           { nome = _nome; }
std::string Cliente::get_nome()                     { return nome; }
void Cliente::set_identificacao(std::string _identificacao)  { identificacao = _identificacao; }
std::string Cliente::get_identificacao()                     { return identificacao; }