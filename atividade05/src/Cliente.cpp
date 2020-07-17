#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

unsigned Cliente::numero_clientes = 0;
Estabelecimento Cliente::estabelecimento;   // permite que todos os clientes dividam os mesmos itens do estabelecimento

Cliente::Cliente()
{
    numero_clientes++;
    id = numero_clientes;
    saldo = 50.0f;
}

Cliente::~Cliente()
{
}

bool Cliente::comprar(int codigo)
{
    // verifica se cliente tem saldo
    for (size_t i=0; i<estabelecimento.produtos.size()-1; ++i)
    {
        if (estabelecimento.produtos[i].codigo == codigo)
        {
            if (saldo - estabelecimento.produtos[i].preco < 0) 
            {
                std::cout << "Saldo não suficiente." << std::endl;
                return false;
            }
        }
    }

    // verifica se estabelecimento tem o produto
    if(!estabelecimento.vender(codigo)) return false;

    Produto item;

    // verifica se sacola está vazia
    if (sacola.size() == 0)
    {
        for (size_t j=0; j<estabelecimento.produtos.size()-1; ++j)
        {
            if (estabelecimento.produtos[j].codigo == codigo)
            {
                item.codigo = estabelecimento.produtos[j].codigo;
                item.descricao = estabelecimento.produtos[j].descricao;
                item.preco = estabelecimento.produtos[j].preco;
                item.quantidade = 1;
                item.unidadeMedida = estabelecimento.produtos[j].unidadeMedida;
            }
        }
        sacola.push_back(item);
        saldo -= item.preco;
        registro();
        return true;
    }
    
    // sacola nao é vazia
    for (size_t i=0; i<sacola.size(); ++i)
    {
        // procura por item já existente na sacola
        if (sacola[i].codigo == codigo) 
        {
            sacola[i].quantidade++;
            saldo -= sacola[i].preco;
            registro();
            return true;
        }
    }
    // se nao houver o item na sacola, adiciona
    for (size_t j=0; j<estabelecimento.produtos.size(); ++j)
    {
        if (estabelecimento.produtos[j].codigo == codigo)
        {
            item.codigo = estabelecimento.produtos[j].codigo;
            item.descricao = estabelecimento.produtos[j].descricao;
            item.preco = estabelecimento.produtos[j].preco;
            item.quantidade = 1;
            item.unidadeMedida = estabelecimento.produtos[j].unidadeMedida;
            sacola.push_back(item);
            saldo -= item.preco;
            registro();
            return true;
        }
    }
    return true;
}

std::string Cliente::verSacola()
{
    std::ostringstream result;

    for (size_t i=0; i<sacola.size(); ++i)
    {
        result << std::setw(5) << sacola[i].codigo << ": ";
        result << std::setw(12) << sacola[i].descricao;
        result << "\tR$ " << std::setw(6) << sacola[i].preco;
        result << "\t" << sacola[i].quantidade;
        result << " " << sacola[i].unidadeMedida;
        result << std::endl;
    }

    return result.str();
}

void Cliente::registro()
{
    // armazena sacola em um arquivo
    std::ostringstream filename;
    filename << "cliente_" << id << ".txt";
    std::ofstream output(filename.str());
    
    output << "COD,NOME,PREÇO,QTD" << std::endl;
    double total = 0.0f;
    for (size_t i=0; i<sacola.size(); ++i)
    {
        output << sacola[i].codigo << ",";
        output << sacola[i].descricao << ",";
        output << "R$ " << sacola[i].preco << ",";
        output << sacola[i].quantidade << std::endl;
        total += sacola[i].preco * sacola[i].quantidade;
    }
    output << "TOTAL GASTO:,," << total << "," << std::endl;

    output.close();
}