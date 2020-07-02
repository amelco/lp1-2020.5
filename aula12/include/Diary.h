#ifndef DIARY_H
#define DIARY_H

#include "Message.h"
#include <string>
#include <vector>

struct Diary
{
  Diary(const std::string& filename);
  ~Diary();

  std::string filename;
  std::vector<Message> messages;

  bool add(const std::string& message); // adiciona string mensagem na lista de mensagens
  bool write();   // escreve no arquivo
  std::vector<Message*> search(std::string what);   // retorna um vector de ponteiros de Mesage

  std::string formated_message(Message message);
};

#endif
