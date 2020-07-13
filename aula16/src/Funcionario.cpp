#include "Funcionario.h"
#include <sstream>

Funcionario::Funcionario() {}
Funcionario::Funcionario(std::string _nome, std::string _empresa, std::string _dep, std::string _data, double _salario) : nome(_nome), empresa(_empresa), departamento(_dep), data_admissao(_data), salario(_salario)
{

}

void Funcionario::set_nome(std::string _nome)                   { nome = _nome; }
void Funcionario::set_empresa(std::string _empresa)             { empresa = _empresa; }
void Funcionario::set_departamento(std::string _departamento)   { departamento = _departamento; }
void Funcionario::set_data_admissao(std::string _data_admissao) { data_admissao = _data_admissao; }
void Funcionario::set_salario(double _salario)                  { salario = _salario; }

std::string Funcionario::get_nome()             { return nome; }
std::string Funcionario::get_empresa()          { return empresa; }
std::string Funcionario::get_departamento()     { return departamento; }
std::string Funcionario::get_data_admissao()    { return data_admissao; }
double Funcionario::get_salario()               { return salario; }

std::string Funcionario::to_string()
{
    std::ostringstream stream;
    stream << "\nNome:\t\t\t" << nome << std::endl;
    stream << "Empresa:\t\t" << empresa << std::endl;
    stream << "Departamento:\t\t" << departamento << std::endl;
    stream << "Data de admissão:\t" << data_admissao << std::endl;
    stream << "Salario:\t\t" << salario << std::endl;
    return stream.str();
}