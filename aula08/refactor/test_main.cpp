#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

#include "Diary.h"
#include "Date.h"
#include "Utils.h"

int main(int argc, char const *argv[])
{
    Diary diario("teste.md");
    for (size_t i = 0; i < 20; i++)
    {
        diario.add("Messagem" + std::to_string(i));
    }
    assert(diario.messages_size == 10);
    std::cout << "Passou teste de tamanho de lista." << std::endl;

    assert( diario.write() );
    std::cout << "Passou teste de escrita no arquivo." << std::endl;

    std::string date = "25/06/2020";
    Date d;
    d.set_from_string(date);
    assert(d.day == 25);
    assert(d.month == 06);
    assert(d.year == 2020);
    std::cout << "Passou teste de set_date_from_string." << std::endl;

    assert(d.to_string() == date);
    std::cout << "Passou teste de Date to_string." << std::endl;

    std::string time = "09:13:00";
    Time t;
    t.set_from_string(time);
    assert(t.hour == 9);
    assert(t.minute == 13);
    assert(t.second == 00);
    std::cout << "Passou teste de set_time_from_string." << std::endl;

    assert(t.to_string() == time);
    std::cout << "Passou teste de Time to_string." << std::endl;

    Utils utils;

    std::string today = utils.get_current_date();
    std::cout << today << std::endl;
    std::string now = utils.get_current_time();
    std::cout << now << std::endl;
    

    return 0;
}
