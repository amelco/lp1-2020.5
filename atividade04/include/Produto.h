#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    public:
    int codigo;
    std::string descricao;
    std::string unidadeMedida;
    double preco;
    unsigned int quantidade;
};

#endif //PRODUTO_H