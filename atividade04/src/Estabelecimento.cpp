#include "Estabelecimento.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

Estabelecimento::Estabelecimento()
{
    arquivo_produtos = "estoque.csv";

    // preenche vector produtos
    size_t num_colunas = 5;
    std::ifstream file(arquivo_produtos);
    std::string line;
    if (file.is_open())
    {
        getline(file, line);    // pula a primeira linha (cabeçalho)
        while (!file.eof())
        {
            std::getline(file, line);
            // lendo valores das variaveis separadas por ','
            int pos = 0;
            std::vector<std::string> valores;
            for (size_t i=0; i<num_colunas; ++i)
            {
                int next_pos;
                next_pos = line.find(',', pos);
                if (i == num_colunas - 1) next_pos = line.find('\n', pos);
                std::string value = line.substr(pos, next_pos-pos);
                // checa se é a variável de preço
                if (value[0] == '"') 
                {
                    pos = line.find('$', pos+1);
                    next_pos = line.find('"', pos);
                    value = line.substr(pos+1, next_pos-pos-1);
                    next_pos = line.find(',', next_pos);
                    // remove espaço após '$' caso exista
                    if (value[0] == ' ') value = value.substr(1);
                    // troca ',' por '.'
                    int pos_virg = value.find(',');
                    value[pos_virg] = '.';
                }
                pos = next_pos+1;
                valores.push_back(value);
                //std::cout << value << std::endl;
            }

            // atribuindo valores a um produto
            Produto item;
            std::stringstream in;
            in << valores[0];
            in >> item.codigo;
            item.descricao = valores[1];
            item.unidadeMedida = valores[2];
            in.clear(); in << valores[3];
            in >> item.preco;
            in.clear(); in << valores[4];
            in >> item.quantidade;
            in.clear();

            // adiciona item aos produtos
            produtos.push_back(item);
        }
    }

    // inicializa vector vendidos
    vendidos = produtos;
    for (size_t i=0; i<vendidos.size(); ++i)
    {
        vendidos[i].quantidade = 0;
    }
}


std::string Estabelecimento::listar()
{
    std::ostringstream result;

    for (size_t i=0; i<produtos.size()-1; ++i)
    {
        result << std::setw(5) << produtos[i].codigo << ": ";
        result << std::setw(12) << produtos[i].descricao;
        result << "\tR$ " << std::setw(6) << produtos[i].preco;
        result << "\t" << produtos[i].unidadeMedida;
        result << "\t" << produtos[i].quantidade;
        result << std::endl;
    }

    return result.str();
}

std::string Estabelecimento::caixa()
{
    std::ostringstream result;
    double ganhos = 0.0f;
    for (size_t i=0; i<vendidos.size()-1; ++i)
    {
        result << std::setw(5) << vendidos[i].codigo << ": ";
        result << std::setw(12) << vendidos[i].descricao;
        result << "\tR$ " << std::setw(6) << vendidos[i].preco;
        result << "\t" << vendidos[i].unidadeMedida;
        result << "\t" << vendidos[i].quantidade;
        result << std::endl;
        ganhos += vendidos[i].preco * vendidos[i].quantidade;
    }
    result << "\n Total ganho: R$ " << ganhos << std::endl;

    return result.str();

}

bool Estabelecimento::vender(int codigo)
{
    bool existe = false;
    // percorre produtos
    for (size_t i=0; i<produtos.size()-1; ++i)
    {
        // checa se o produto é o que se quer comprar
        if (produtos[i].codigo == codigo)
        {
            existe = true;
            // diminui a qtd do produto
            if (produtos[i].quantidade == 0) return false;
            produtos[i].quantidade--;
        }
    }

    if (!existe) return false;

    // percorre lista do vendidos
    for (size_t i=0; i<vendidos.size()-1; ++i)
    {
        // aumenta quantidade do produto caso exista
        if (vendidos[i].codigo == codigo)
        {
            vendidos[i].quantidade++;
        }
    }

    // armazena caixa em arquivo
    std::ofstream output("caixa.csv");
    
    output << "COD,NOME,PREÇO,QTD" << std::endl;
    double total = 0.0f;
    for (size_t i=0; i<vendidos.size()-1; ++i)
    {
        output << vendidos[i].codigo << ",";
        output << vendidos[i].descricao << ",";
        output << "R$ " << vendidos[i].preco << ",";
        output << vendidos[i].quantidade << std::endl;
        total += vendidos[i].preco * vendidos[i].quantidade;
    }
    output << "TOTAL VENDIDO:,," << total << "," << std::endl;

    output.close();

    return true;
}