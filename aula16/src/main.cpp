#include <iostream>
#include "Empresa.h"
#include "Funcionario.h"

int main (int argc, char* argv[])
{
    unsigned num_funcionarios;
    Empresa empresa("UFRN", "123456700011");

    std::cout << "Empresa: " << empresa.get_nome() << std::endl;
    std::cout << "Quantos funcionários deseja cadastrar?" << std::endl;
    std::cin >> num_funcionarios;

    for (size_t i=0; i<num_funcionarios; ++i)
    {
        std::string nome, dep, data;
        double sal;
        std::cout << "\nAdicione funcionario " << i+1 << ":" << std::endl;
        std::cout << "Nome: "; std::cin >> nome;
        std::cout << "Departamento: "; std::cin >> dep;
        std::cout << "Data de admissão: "; std::cin >> data;
        std::cout << "Salario: "; std::cin >> sal;
        Funcionario funcionario(nome, empresa.get_nome(), dep, data, sal);
        empresa.add_funcionario(funcionario);
    }

    std::cout << empresa.lista_funcionarios() << std::endl;

    std::string dep;
    std::cout << "Deseja aumentar em 10% o salario de qual departamento? [digite o nome]" << std::endl;
    std::cout << empresa.lista_departamentos() << std::endl;
    std::cin >> dep;
    empresa.aumentar_salario_departamento(dep);

    std::cout << empresa.lista_funcionarios() << std::endl;

    return 0;
}