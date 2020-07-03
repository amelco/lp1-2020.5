#include "Diary.h"
#include "Utils.h"

#define DEBUG std::cout << "aqui" << std::endl;

#include <string>
#include <fstream>
#include <sstream>

#include <iostream>

Diary::Diary(const std::string &_filename) : filename(_filename)
{
  format = "[%d %t] %m";
  std::ifstream file(filename);
  if (file.is_open()) // arquivo existe
  {
    std::string date, time, content;
    while (!file.eof())
    {
      std::string line;
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

      Message msg;
      msg.date.set_from_string(date);
      msg.time.set_from_string(time);
      msg.content = content;

      messages.push_back(msg);
    }
  }
    
  file.close();
}

Diary::~Diary()
{
}

bool Diary::add(const std::string &message)
{
  // adiciona nova mensagem na array de mensagens
  Message msg;
  Utils utils;
  msg.content = message;
  msg.date.set_from_string(utils.get_current_date());
  msg.time.set_from_string(utils.get_current_time());

  messages.push_back(msg);

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
  for (size_t i=0; i<messages.size(); ++i)
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

 std::vector<Message*> Diary::search(std::string what)
{
  std::vector<Message*> result;
  Message* msg;
  for (size_t i=0; i<=messages.size(); ++i)
  {
    // find(): retorna posição do 1o char do texto encontrado
    //         retorna tamanho da string caso nao tenha encontrado
    std::size_t found = messages[i].content.find(what);
    if (found < messages[i].content.npos) 
    {
      msg = &messages[i];
      result.push_back(msg);
    }
  }
  return result;
}

std::string Diary::formated_message(Message message)
{
  std::stringstream stream;

  for (size_t i=0; i<format.length(); ++i)
  {
    if (format[i] == '%')
    {
      if (format[i+1] == 'd') { stream << message.date.to_string().substr(2,10); ++i;}
      else if (format[i+1] == 't') { stream << message.time.to_string().substr(2,8); ++i;}
      else if (format[i+1] == 'm') { stream << message.content; ++i;}
      else stream << format[i];
    }
    else
    {
      stream << format[i];
    }
    
  }
 
  /*
  stream << message.date.to_string().substr(2,10) << " ";
  stream << message.time.to_string().substr(2,8) << " ";
  stream << message.content;
  */

  return stream.str();
}