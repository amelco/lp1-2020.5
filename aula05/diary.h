#ifndef DIARY_H
#define DIARY_H

#include "message.h"


struct Diary
{
  Message* messages;

  bool add(Message);
  void list();
  void show_usage();
};

#endif  // DIARY_H
