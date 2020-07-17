#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "Fornecedor.h"


Fornecedor::Fornecedor()
{
    // preenche vector produtos
    size_t num_colunas = 2;
    std::ifstream file("fornecedor.csv");
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
                pos = next_pos+1;
                valores.push_back(value);
            }
            // atribuindo valores a um produto
            Produto item;
            std::stringstream stream;
            item.codigo = -1;
            item.descricao = valores[0];
            item.unidadeMedida = "";
            item.preco = -1;
            stream << valores[1];
            stream >> item.quantidade;

            // adiciona item aos produtos
            produtos.push_back(item);
        }
    }
}

std::string Fornecedor::listar_produtos()
{
    std::ostringstream result;

    for (size_t i=0; i<produtos.size()-1; ++i)
    {
        result << std::setw(12) << produtos[i].descricao;
        result << "\t" << produtos[i].quantidade;
        result << std::endl;
    }

    return result.str();
}

bool Fornecedor::repassar_produto(std::string nome, int quant)
{
    for (size_t i=0; i<produtos.size(); ++i)
    {
        if (produtos[i].descricao == nome && produtos[i].quantidade > 0)
        {
            produtos[i].quantidade -= quant;
            return true;
        }
    }
    return false;
}