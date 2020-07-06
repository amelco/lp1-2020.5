#include <iostream>
#include "conta.h"

int main(int argc, char const *argv[])
{
    Conta c1("Fulano de Tal", "0001");
    Conta c2("Cicrano de Tal", "0002");

    std::cout << "Conta:\t" << c1.numero << "\t" << c2.numero << std::endl;
    std::cout << "Saldo:\t" << c1.saldo << "\t" << c2.saldo << std::endl;
    std::cout << "\nDepósitos\n";

    c1.deposita(100.0f);
    c2.deposita(50.0f);

    std::cout << "Conta:\t" << c1.numero << "\t" << c2.numero << std::endl;
    std::cout << "Saldo:\t" << c1.saldo << "\t" << c2.saldo << std::endl;
    std::cout << "\nTransferência\n";

    c1.transfere(25.0f, c2);

    std::cout << "Conta:\t" << c1.numero << "\t" << c2.numero << std::endl;
    std::cout << "Saldo:\t" << c1.saldo << "\t" << c2.saldo << std::endl;

    return 0;
}
