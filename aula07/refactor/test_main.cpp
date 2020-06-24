#include <iostream>
#include <string>
#include <cassert>

#include "Diary.h"

int main(int argc, char const *argv[])
{
    Diary diario("teste.md");
    for (size_t i = 0; i < 20; i++)
    {
        diario.add("Messagem" + std::to_string(i));
    }
    assert(diario.messages_size == 10);
    std::cout << "Passou teste de tamanho de lista." << std::endl;

    assert( diario.write() );
    std::cout << "Passou teste de escrita no arquivo." << std::endl;

    return 0;
}
