#ifndef DIARY_H
#define DIARY_H

#include "Message.h"
#include <string>

struct Diary
{
  Diary(const std::string& filename);
  ~Diary();

  std::string filename;
  Message* messages;
  size_t messages_size;     // numero de mensagens
  size_t messages_capacity; // tamanho da mensagem

  bool add(const std::string& message); // adiciona mensagem na lista de mensagens
  void write();   // escreve no arquivo
};

#endif
