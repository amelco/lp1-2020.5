#include "Empresa.h"
#include <sstream>
#include <iostream>

// std::vector<Funcionario> Empresa::funcionarios;

Empresa::Empresa(std::string _nome, std::string _cnpj) : nome(_nome), cnpj(_cnpj)
{
}

void Empresa::set_nome(std::string _nome) { nome = _nome; }
void Empresa::set_cnpj(std::string _cnpj) { cnpj = _cnpj; }

std::string Empresa::get_nome() { return nome; }
std::string Empresa::get_cnpj() { return cnpj; }

void Empresa::add_funcionario(Funcionario _funcionario)
{
    if (_funcionario.get_empresa() != nome)
    {
        std::cout << "Erro ao adicionar usuário." << std::endl;
        std::cout << "Motivo:  usuário " << _funcionario.get_nome() << " não pertence à Empresa " << nome << "." << std::endl;
        std::cout << "Solução: cadastre a empresa " << _funcionario.get_empresa() << " e adicione-o novamente." << std::endl;
        return;
    }
    funcionarios.push_back(_funcionario);
}

std::string Empresa::lista_funcionarios()
{
    std::ostringstream stream;
    stream << "\t -== Lista de funcionários ==-\n";
    for (size_t i=0; i<funcionarios.size(); ++i)
    {
        stream << funcionarios[i].to_string();
    }
    return stream.str();
}

std::string Empresa::lista_departamentos()
{
    std::vector<std::string> unique_deps;
    std::ostringstream stream;
    stream << "\t -== Lista de departamentos ==-\n";
    for (size_t i=0; i<funcionarios.size(); ++i)
    {
        bool dep_exists = false;
        for (size_t j=0; j<unique_deps.size(); ++j)
            if (unique_deps[j] == funcionarios[i].get_departamento()) 
            {
                dep_exists = true;
                break;
            }
        if (!dep_exists) 
        {
            unique_deps.push_back(funcionarios[i].get_departamento());
            stream << i+1 << ") " << funcionarios[i].get_departamento() << std::endl;
        }
    }
    return stream.str();
}

void Empresa::aumentar_salario_departamento(std::string nome_departamento)
{
    bool dep_exists = false;
    for (size_t i=0; i<funcionarios.size(); ++i)
    {
        if (funcionarios[i].get_departamento() == nome_departamento)
        {
            dep_exists = true;
            funcionarios[i].set_salario(funcionarios[i].get_salario() * 1.1);
        }
    }
    if (!dep_exists) std::cout << "Departamento " << nome_departamento << " não existe.\nVerifique o nome e tente novamente.\n" << std::endl;
    else std::cout << "Salários do pessoal do departamento " << nome_departamento << " aumentado com sucesso!\n" << std::endl;
}