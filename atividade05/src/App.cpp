#include "App.h"
#include "Estabelecimento.h"
#include "Produto.h"
#include "Cliente.h"
#include "Fornecedor.h"
#include <iostream>

int App::run()
{
    char op = 's';
    while (op == 's') 
    {
        novo_cliente();
        
        std::cout << "Deseja entrar como outro cliente? (s/n)" << std::endl;
        std::cin >> op;
        std::cin.ignore(1); // lê somente um char e limpa buffer
    }

    return 0;
}

void App::novo_cliente()
{
    Cliente cliente;
    std::string menu = "Supermercado\n\n\n";
    menu += "Selecione uma opção:\n\n";
    menu += "1) Listar produtos\n";
    menu += "2) Comprar\n";
    menu += "3) Ver sacola\n";
    menu += "4) Listar produtos do fornecedor\n";
    menu += "5) Reabastecer estoque do supermercado\n\n";
    menu += "0) Finalizar\n\n";

    char op;
    while (op != '0')
    {
        std::cout << menu;
        std::cout << "Seu saldo: R$ " << cliente.saldo << "\nOpção: ";
        std::cin >> op;
        std::cin.ignore(1);
        if (op == '1')
        {
            std::cout << cliente.estabelecimento.listar() << std::endl;
            std::cout << "\nPressione Enter para continuar..." << std::endl;
            std::cin.ignore();
        }
        else if (op == '2')
        {
            unsigned prod_id;
            std::cout << "Qual o id do produto? ";
            std::cin >> prod_id;
            std::cin.ignore();
            std::cout << std::endl;
            if (cliente.comprar(prod_id)) std::cout << "Compra efetuada!" << std::endl;
            std::cout << "\nPressione Enter para continuar..." << std::endl;
            std::cin.ignore();
        }
        else if (op == '3')
        {
            std::cout << cliente.verSacola() << std::endl;
            std::cout << "\nPressione Enter para continuar..." << std::endl;
            std::cin.ignore();
        }
        else if (op == '4')
        {
            std::cout << cliente.estabelecimento.fornecedor.listar_produtos() << std::endl;
            std::cout << "\nPressione Enter para continuar..." << std::endl;
            std::cin.ignore();
        }
        else if (op == '5')
        {
            std::string prod_name;
            unsigned quant;
            std::cout << "Qual o nome do produto que deseja reabastecer? ";
            std::getline(std::cin, prod_name);
            std::cout << "Qual a quantidade? ";
            std::cin >> quant;
            std::cin.ignore();
            if (cliente.estabelecimento.reabastecer(prod_name, quant)) std::cout << "Reabastecimento efetuado!" << std::endl;
            else std::cout << "Produto não disponível" << std::endl;
            std::cout << "\nPressione Enter para continuar..." << std::endl;
            std::cin.ignore();
        }
    }
    std::cout << "\nAté breve.\n" << std::endl;
}