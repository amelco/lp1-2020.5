#ifndef DIARY_H
#define DIARY_H

#include "message.h"


struct Diary
{
  Message* messages;

  std::string filename = "diario.md";
  bool add(Message);
  void list();
  void show_usage();

private:
  bool write_in_file(Message msg);
  bool date_exists(Date date);
};

#endif  // DIARY_H
