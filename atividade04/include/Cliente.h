#ifndef CLIENTE_H
#define CLIENTE_H

#include "Produto.h"
#include "Estabelecimento.h"
#include <vector>
#include <string>

class Cliente
{
    public:
    static unsigned numero_clientes;
    static Estabelecimento estabelecimento;

    unsigned id;
    double saldo;
    std::vector<Produto> sacola;

    bool comprar(int codigo);
    std::string verSacola();
    void registro();

    void ver();

    Cliente();
    ~Cliente();
};

#endif // CLIENTE_H