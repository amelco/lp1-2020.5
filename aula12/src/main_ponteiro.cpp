#include <iostream>

struct MyStruct {
    int variable;
    void funcao() {}
    int* ptn;
};

void por_copia(int a)
{
    a = 30;
}

void por_referencia(int &a) // aqui, a é apelido
{
    a = 30;
}

void por_ponteiro(int *a)
{
    *a = 40;
}

int main(int argc, char const *argv[])
{
    // 1o uso
    int a = 10;
    int* b = &a;

    std::cout << "Endereço: " << b << std::endl;
    std::cout << "Valor:    " << *b << std::endl;   //Derreferência

    *b = 20;
    std::cout << a << std::endl;

    // 2o uso
    char* c = new char[10];
    // 3o uso
    int* d = nullptr;

    // referencia
    //   é um "apelido" para a variavel
    //   nao pode receber nulo
    int joao = 10;
    int &joaozinho = joao;

    joaozinho = 20;

    std::cout << joao << std::endl;

    int n = 10;
    int &n2 = n;
    int *n3 = &n;

    std::cout << &n << std::endl;
    std::cout << &n2 << std::endl;
    std::cout << n3 << std::endl;

    por_copia(n);
    std::cout << n << std::endl;
    por_referencia(n);
    std::cout << n << std::endl;
    por_ponteiro(&n);
    std::cout << n << std::endl;

    // Usando ponteiro ou referencia numa função:
    //  sempre que usar ponteiro, o valor pode ser nullptr
    //  com referencia isso nao acontece
    //  entao:
    //      se a variavel for opcional (pode passar nulo), usa ponteiro
    //      se a variavel for obrigatoria, usa referencia


    int arr[] = {10, 20, 30, 40};   // ponteiro para o 1o elemento do array
    std::cout << *arr << std::endl;

    // acessando o segundo elemento utilizando aritmetica de ponteiro
    std::cout << *(arr + 1) << std::endl;  

    // ou seja: arr[0] == *arr
    //          arr[1] == *(arr + 1)
    // e assim por diante

    MyStruct s;
    MyStruct *p = &s;

    s.funcao();     // acessando elementos de struct pela variavel
    s.variable = 10;
    p->funcao();    // acessando elementos de struct por ponteiro
    p->variable = 20;

    std::cout << s.variable << std::endl;

    s.ptn = &argc;  // exemplo de uso de ponteiro dentro da struct

    // mudando endereços dos ponteiros
    int k = 10;
    int l = 20;
    int* m = &a;
    *m = 50;
    m = &l;
    *m = 100;

    std::cout << k << std::endl;
    std::cout << l << std::endl;

    // Observações:
    // sempre que for derreferenciar um ponteiro, checar se ele é nulo
    // cuidado com o escopo da variável ao retornar seu endereço

    return 0;
}
