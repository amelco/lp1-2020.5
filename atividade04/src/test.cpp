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
    if (!c1.comprar(17)) std::cout << "erro na compra" << std::endl;
    if (!c1.comprar(1)) std::cout << "erro na compra" << std::endl;
    std::cout << c1.verSacola() << std::endl;

    Cliente c2;
    if (!c2.comprar(1)) std::cout << "erro na compra" << std::endl;
    if (!c2.comprar(2)) std::cout << "erro na compra" << std::endl;
    if (!c2.comprar(2)) std::cout << "erro na compra" << std::endl;
    std::cout << c2.verSacola() << std::endl;

    return 0;
}