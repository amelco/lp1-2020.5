#include "App.h"

#include <string>

int main(int argc, char* argv[])
{
  std::string filename = "diary.md";
  App aplicativo(filename);
  return aplicativo.run(argc, argv);
}
