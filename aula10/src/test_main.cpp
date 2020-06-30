#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

#include "Diary.h"
#include "Date.h"
#include "Utils.h"

int main(int argc, char const *argv[])
{
    Diary d("teste.md");
    d.add("CODIGO");
    d.write();

    for (size_t i=0; i<d.messages_size; ++i)
    {
        std::cout << i << d.messages[i].content << std::endl;
    }
}
