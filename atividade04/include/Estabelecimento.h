#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include "Produto.h"
#include <string>
#include <vector>

class Estabelecimento
{
    public:
    std::string arquivo_produtos;
    std::vector<Produto> produtos;
    std::vector<Produto> vendidos;

    std::string listar_geral(std::vector<Produto>& _produtos);
    std::string listar();
    std::string caixa();
    bool vender(int codigo);

    Estabelecimento();
    ~Estabelecimento();
};

#endif  // ESTABELECIMENTO_H