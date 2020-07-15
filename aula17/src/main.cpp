#include <iostream>
#include "Cliente.h"
#include "ClientePJ.h"
#include "Fila.h"

int main(int argc, char const *argv[])
{
    Cliente f1("Fulano Pessoa Física", "123.456.789-01");
    Cliente f2("Beltrano Pessoa Física", "234.567.890-12");
    Cliente f3("Cicrano Pessoa Física", "345.678.901-23");

    ClientePJ j1("Fulano Pessoa Jurídica", "12.345.678/0001-90");
    ClientePJ j2("Beltrano Pessoa Jurídica", "23.456.789/0001-01");

    Fila<Cliente> fila(2);

    fila.adiciona(f2);
    fila.adiciona(f1);
    fila.adiciona(f3);

    Cliente temp = fila.primeiro();
    
    std::cout << "O primeiro da fila é:\n" << temp.to_string() << std::endl;
    fila.remove();

    temp = fila.primeiro();
    std::cout << "O primeiro da fila é:\n" << temp.to_string() << std::endl;
    fila.remove();

    Fila<ClientePJ> filaPJ(2);

    filaPJ.adiciona(j2);
    ClientePJ tempPJ = filaPJ.ultimo();
    std::cout << "O último da fila é:\n" << tempPJ.to_string() << std::endl;
    
    filaPJ.adiciona(j1);
    tempPJ = filaPJ.ultimo();
    std::cout << "O último da fila é:\n" << tempPJ.to_string() << std::endl;
        
    return 0;
}
