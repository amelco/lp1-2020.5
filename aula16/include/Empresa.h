#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <vector>
#include "Funcionario.h"

class Empresa
{
    private:
    std::string nome;
    std::string cnpj;
    std::vector<Funcionario> funcionarios;

    public:
    Empresa(std::string _nome, std::string cnpj);

    void set_nome(std::string _nome);
    void set_cnpj(std::string _cnpj);

    std::string get_nome();
    std::string get_cnpj();

    void add_funcionario(Funcionario _funcionario);
    std::string lista_funcionarios();
    std::string lista_departamentos();
    void aumentar_salario_departamento(std::string nome_departamento);

};

#endif // EMPRESA_H