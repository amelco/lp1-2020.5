#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
    private:
    std::string nome;
    std::string empresa;
    std::string departamento;
    std::string data_admissao;
    double salario;

    public:
    Funcionario();
    Funcionario(std::string _nome, std::string _empresa, std::string _dep, std::string _data, double _salario);

    void set_nome(std::string _nome);
    void set_empresa(std::string _empresa);
    void set_departamento(std::string _departamento);
    void set_data_admissao(std::string _data_admissao);
    void set_salario(double _salario);

    std::string get_nome();
    std::string get_empresa();
    std::string get_departamento();
    std::string get_data_admissao();
    double get_salario();

    std::string to_string();
};

#endif // FUNCIONARIO_H