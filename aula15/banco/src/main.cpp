#include <iostream>
#include "Conta.h"

int main(int argc, char const *argv[])
{
    Conta c1("Fulano de Tal", "012345678-90", "0001");
    Conta c2("Cicrano de Tal", "123456789-01", "0002");

    std::cout << "\n\t-== SUMÁRIO DAS CONTAS ==-\n" << std::endl;
    std::cout << "               \t" << "Cliente 1\t"     << "Cliente 2\t\t"             << std::endl;
    std::cout << "Nome Agencia:  \t" << c1.agencia.nome   << "\t" << c2.agencia.nome     << std::endl;
    std::cout << "Número Agencia:\t" << c1.agencia.numero << "\t\t" << c2.agencia.numero << std::endl;
    std::cout << "Nome Cliente:  \t" << c1.cliente.nome   << "\t" << c2.cliente.nome     << std::endl;
    std::cout << "CPF Cliente:   \t" << c1.cliente.cpf    << "\t" << c2.cliente.cpf      << std::endl;

    std::cout << "\nConta:\t\t" << c1.numero << "\t\t" << c2.numero << std::endl;
    std::cout << "Saldo:\t\t"   << c1.saldo  << "\t\t" << c2.saldo  << std::endl;
    std::cout << "\nDepósitos\n";

    c1.deposita(100.0f);
    c2.deposita(50.0f);

    std::cout << "Conta:\t\t" << c1.numero << "\t\t" << c2.numero << std::endl;
    std::cout << "Saldo:\t\t" << c1.saldo  << "\t\t"  << c2.saldo  << std::endl;
    std::cout << "\nTransferência\n";

    c1.transfere(25.0f, c2);

    std::cout << "Conta:\t\t" << c1.numero << "\t\t" << c2.numero << std::endl;
    std::cout << "Saldo:\t\t" << c1.saldo  << "\t\t" << c2.saldo  << std::endl;

    return 0;
}
