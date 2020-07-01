#include <iostream>
#include <vector>

struct Qualquer
{
    int valor;
};

int main(int argc, char const *argv[])
{
    // VECTOR

    std::vector<int> items;
    std::vector<Qualquer> items2;
    std::vector<std::vector> items3;    // vetor de vetores (matriz)

    // containers sempre armazenam na memória heap
    // adicionando items no vector
    for (size_t i = 0; i < 1000; i++)
    {
    items.push_back(i);
    }
    
    // adicionando items no vector
    items.push_back(10);
    items.push_back(20);
    items.push_back(30);
    items.push_back(40);

    // mostrando elementos
    std::cout << items[0] << std::endl;
    // usando items.size()
    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout << items[0] << std::endl;
    }

    // usando items.capacity()
    // capacity() vai dobrando de valor a medida que se precisa adicionar mais valores
    std::cout << items.capacity() << std::endl;

    {
        Qualquer q1;
        Qualquer q2;   

        q1.valor = 10;
        q2.valor = 20;

        items2.push_back(q1);
        items2.push_back(q2);
    }
    // Aqui q1 e q1 nao existem mas os valores podem ser acessados 
    //   em items2, pois items2 está na heap


    // UNORDERED MAP (dicionário)

    std::unordered_map<std::string, int> dicionario;
    
    // não tem sequencia, como o vector
    //         chave      valor  
    dicionario["fulano"]  = 10;
    dicionario["cicrano"] = 8;

    // iteração no dicionário (usando iteradores)


    // ITERADORES
    // os containers tem as funções begin() e end()
    dicionario.begin();     // aponta pro primeiro elemento
    dicionario.end();       // aponta pra depois do ultimo elemento
    items.begin();
    items.end();

    // usa o end() pra verificar se a coleção acabou
    // o iterator tem um tipo  proprio

    // exemplo
    for ( std::vector<int>::iterator it = items.begin(); it < items.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    for ( std::unordered_map<std::string, int>::iterator it = dicionario.begin(); it < dicionario.end(); ++it)
    {
        // nesse caso, o iterator é do tipo pair, pois precisa de chave e valor
        std::cout << it->first << std::endl;        // chave
        std::cout << it->second << std::endl;       // valor
    }

    // podemos declarar uma variavel que o compilador infgewre o tipo
    // auto (C++11)
    for ( auto it = dicionario.begin(); it < dicionario.end(); ++it)
    {

    }

    // auto deve ser sempre inicializado
    auto n  = 10;      // inteiro
    auto n2 = 5.2f;    // float


    // ranged for loop (C++11)
    for (int i : items)
    {
        std::cout << i << std::endl;
    }

    for (auto i : dicionario)
    {
        std::cout << i.first << std::endl;
        std::cout << i.second << std::endl;
    }

    // ordenando 
    std::sort(dicionario.begin(), dicionario.end());

    return 0;
}
