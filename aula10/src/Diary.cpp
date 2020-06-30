#include "Diary.h"
#include "Utils.h"

#define DEBUG std::cout << "aqui" << std::endl;

#include <string>
#include <fstream>

#include <iostream>

Diary::Diary(const std::string &_filename) : filename(_filename),
                                             messages(nullptr),
                                             messages_size(0)
{
  // No inicio do programa, atribui message_capacity como o numero das mensagens existentes
  //   ou 10 caso o arquivo seja novo
  std::ifstream file(filename);
  if (file.is_open()) // arquivo existe
  {
    std::string line;
    size_t num_msgs = 0;
    while (!file.eof())
    {
      std::getline(file, line);
      if (line[0] == '-')
        num_msgs++;
    }
    messages_size = num_msgs;
    messages_capacity = messages_size;
    if (messages_capacity < 10)
      messages_capacity = 10;
    
    // voltando ao inicio do arquivo
    file.clear();
    file.seekg(0);

    // Armazena mensagens do arquivo de texto no array de mensagens
    messages = new Message[messages_capacity];
    std::string date, time, content;
    size_t i = 0;
    while (!file.eof())
    {
      std::getline(file, line);
      // pega as respectivas substrings para date, time e content
      if (line.size() == 0) continue;
      if (line[0] == '#') {
        date = line.substr(2,10);
        continue;
      }
      if (line[0] == '-') { 
        time = line.substr(2,8);
        content = line.substr(11);
      }

      messages[i].date.set_from_string(date);
      messages[i].time.set_from_string(time);
      messages[i].content = content;
      i++;
    }
  }
  else // arquivo novo
  {
    messages_size = 0;
    messages_capacity = 10;
    messages = new Message[messages_capacity];
  }
    
  file.close();
}

Diary::~Diary()
{
  delete[] messages;
  messages = nullptr;
}

bool Diary::add(const std::string &message)
{
  // aumenta o tamanho da matriz
  if (messages_size >= messages_capacity)
  {
    // cria cópia da array
    Message* copy = new Message[messages_capacity];
    for (size_t i=0; i<messages_capacity; ++i)
      copy[i] = messages[i];
   
    // aloca array com novo tamanho após desalocá-la
    delete[] messages;
    messages = nullptr;
    messages = new Message[2 * messages_capacity];
    
    // transfere da cópia para a array redimensionada
    for (size_t i=0; i<messages_capacity; ++i)
      messages[i] = copy[i];

    // desaloca a cópia
    delete[] copy;

    messages_capacity *= 2;
    // std::cout << messages[0].content << std::endl;
  }

  // adiciona nova mensagem na array de mensagens
  Message msg;
  Utils utils;
  msg.content = message;
  msg.date.set_from_string(utils.get_current_date());
  msg.time.set_from_string(utils.get_current_time());
  messages[messages_size] = msg;
  messages_size++;
  return true;
}

// escreve todo o array da memória num arquivo
bool Diary::write()
{
  // garante criação de novo arquivo antes da escrite
  std::ofstream ofile(filename);
  ofile.close();

  std::ofstream file(filename, std::ios::app);
  if (file.fail()) return false;

  std::string date = messages[0].date.to_string();
  for (size_t i=0; i<messages_size; ++i)
  {
    // adiciona data apenas quando mudar de dia
    if (i == 0) file << messages[i].date.to_string() << std::endl;
    if (messages[i].date.to_string() != date) file << std::endl << messages[i].date.to_string() << std::endl;
    
    file << messages[i].time.to_string() << " ";
    file << messages[i].content << std::endl;
    date = messages[i].date.to_string();
  }
  
  file.close();
  return true;
}