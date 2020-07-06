#include "Conta.h"

Conta::Conta(std::string _titular, std::string _numero) : titular(_titular), numero(_numero)
{
    this->saldo = 0.0f;
}

void Conta::saca(double valor)
{
    this->saldo -= valor;
}

void Conta::deposita(double valor)
{
    this->saldo += valor;
}

void Conta::transfere(double valor, Conta &conta)
{
    conta.deposita(valor);
    this->saldo -= valor;
}