#include <iostream>

#include "Estabelecimento.h"
#include "Produto.h"
#include "Cliente.h"

int main(int argc, char* argv[])
{
    // Estabelecimento e1;

    // if (!e1.vender(1)) std::cout << "Produto não está disponível." << std::endl;
    // if (!e1.vender(17)) std::cout << "Produto não está disponível." << std::endl;
    // if (!e1.vender(17)) std::cout << "Produto não está disponível." << std::endl;
    // if (!e1.vender(19)) std::cout << "Produto não está disponível." << std::endl;

    //std::cout << e1.listar() << std::endl;
    //std::cout<< e1.caixa() << std::endl;

    Cliente c1;
    c1.comprar(11);
    c1.comprar(11);
    std::cout << c1.verSacola() << std::endl;

    Cliente c2;
    c2.comprar(11);
    c2.comprar(2);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    c2.comprar(1);
    std::cout << c2.verSacola() << std::endl;

    return 0;
}