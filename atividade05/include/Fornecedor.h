#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <iostream>
#include <string>
#include "vetor_supermercado.h"
#include "Produto.h"

class Fornecedor
{
public:
    vetor_supermercado<Produto> produtos;
    
    Fornecedor();
    std::string listar_produtos();      // (mostra todos os produtos disponíveis) 
    bool repassar_produto(std::string nome, int quantidade);     // (repassa para o estabelecimento os produtos solicitados na quantidade solicitada, diminuindo seus valores em fornecedor.csv);

};

#endif // FORNECEDOR_H