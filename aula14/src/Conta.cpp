#include "Conta.h"

Conta::Conta(std::string _titular, std::string _cpf, std::string _numero) : numero(_numero)
{
    this->saldo = 0.0f;
    this->cheque_especial = false;
    this->cliente.nome = _titular;
    this->cliente.cpf = _cpf;
    this->agencia.nome = "Fictícia";
    this->agencia.numero = 0001;
}

void Conta::saca(double valor)
{
    this->saldo -= valor;
    if (saldo < 0.0f) this->cheque_especial = true;
}

void Conta::deposita(double valor)
{
    this->saldo += valor;
    if (saldo >= 0.0f) this->cheque_especial = false;
}

void Conta::transfere(double valor, Conta &conta)
{
    conta.deposita(valor);
    this->saldo -= valor;
    if (saldo < 0.0f) this->cheque_especial = true;
}
