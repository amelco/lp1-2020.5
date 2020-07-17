#include <iostream>
#include "vetor_supermercado.h"

int main(int argc, char const *argv[])
{
    vetor_super<int> lista;
    std::cout << lista.capacity() << std::endl;
    std::cout << lista.size() << std::endl;

    for (size_t i=0; i<lista.capacity(); ++i)
    {
        lista.push_back(i+1);
    }
    std::cout << lista.capacity() << std::endl;
    std::cout << lista.size() << std::endl;

    lista.push_back(11);
    std::cout << lista.capacity() << std::endl;
    std::cout << lista.size() << std::endl;

    std::cout << lista[0] << std::endl;

    return 0;
}
