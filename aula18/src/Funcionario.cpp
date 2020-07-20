#include "Funcionario.h"

#include <sstream>

Funcionario::Funcionario() {}
Funcionario::Funcionario(std::string _nome, unsigned _matricula) : nome(_nome), matricula(_matricula) {}
Funcionario::~Funcionario() {}


void Funcionario::set_nome(std::string _nome)           { nome = _nome; }
std::string Funcionario::get_nome()                     { return nome; }
void Funcionario::set_matricula(unsigned _matricula)    { matricula = _matricula; }
unsigned Funcionario::get_matricula()                   { return matricula; }