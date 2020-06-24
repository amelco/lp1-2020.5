#include "../include/App.h"

#include <iostream>

int App::run(int argc, char* argv[])
{
    if (argc == 1)
    {
        show_usage();
    }
    return 0;
}

void App::show_usage()
{
    std::cout << "Usage: " << std::endl;
}