#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include "Produto.h"
#include "vetor_supermercado.h"
#include "Fornecedor.h"
#include <string>

class Estabelecimento
{
    public:
    std::string arquivo_produtos;
    vetor_supermercado<Produto> produtos;
    vetor_supermercado<Produto> vendidos;
    Fornecedor fornecedor;

    std::string listar_geral(vetor_supermercado<Produto>& _produtos);
    std::string listar();
    std::string caixa();
    bool vender(int codigo);
    bool reabastecer(std::string nome, int quantidade);

    Estabelecimento();
    ~Estabelecimento();
};

#endif  // ESTABELECIMENTO_H