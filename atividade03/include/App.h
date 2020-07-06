/*
 * Responsável pela visualização do programa
 */
#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>

struct App
{
  App(std::string& filename);
  Diary diary;
  
  int run(int argc, char* argv[]);
  int show_usage();
  void add();
  void add(const std::string& message);
  void search();
  void search(const std::string what);
  void list_messages();
  void interactive_mode();

};

#endif
