#ifndef CLIENTE_H
#define CLIENTE_H

#include "Produto.h"
#include "Estabelecimento.h"
#include "vetor_supermercado.h"
#include <string>

class Cliente
{
    public:
    static unsigned numero_clientes;
    static Estabelecimento estabelecimento;

    unsigned id;
    double saldo;
    vetor_supermercado<Produto> sacola;

    bool comprar(int codigo);
    std::string verSacola();
    void registro();

    Cliente();
    ~Cliente();
};

#endif // CLIENTE_H