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
  size_t messages_size;     // numero de mensagens armazenadas
  size_t messages_capacity; // tamanho da mensagem

  bool add(const std::string& message); // adiciona string mensagem na lista de mensagens
  bool write();   // escreve no arquivo

  // ./diary search bom => retornar a primeira msg encontrada
  // metodo find() do array
  Message* search(std::string what); // retorna o endereço da msg ou nullptr, caso nao exista
};

#endif
