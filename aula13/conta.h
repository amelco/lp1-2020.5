#include <string>

class Conta
{
    public:
        std::string numero;
        std::string titular;
        double saldo;

        void saca(double valor);
        void deposita(double valor);
        void transfere(double valor, Conta &conta);

        Conta(std::string _titular, std::string _numero);
};