#include "Cliente.h"
#include <iostream>

unsigned Cliente::numero_clientes = 0;
Estabelecimento Cliente::estabelecimento;   // permite que todos os clientes dividam os mesmos itens do estabelecimento

Cliente::Cliente()
{
    numero_clientes++;
    id = numero_clientes;
    saldo = 50.0f;
    estabelecimento.vender(17);
}

Cliente::~Cliente()
{
}

void Cliente::ver()
{
    std::cout << estabelecimento.caixa() << std::endl;
}