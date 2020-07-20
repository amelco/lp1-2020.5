#ifndef CONTA_H
#define CONTA_H

#include "ClientePF.h"
#include "Agencia.h"
#include <string>

class Conta
{
    public:
        std::string numero;
        std::string titular;
        Agencia agencia;
        ClientePF cliente;
        double saldo;
        bool cheque_especial;

        void saca(double valor);
        void deposita(double valor);
        void transfere(double valor, Conta &conta);

        Conta(std::string _titular, std::string cpf, std::string _numero);
};

#endif  // CONTA_H
