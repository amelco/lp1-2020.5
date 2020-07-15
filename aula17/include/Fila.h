#ifndef FILA_H
#define FILA_H

#include <iostream>

template<typename T>
class Fila
{
    private:
    int tamanho;
    int ultimo_pos;
    T* valor;

    public:

    Fila(int tam)
    {
        tamanho = tam;
        valor = new T[tamanho];
        ultimo_pos = -1;
    }

    void adiciona(T cliente)
    {
        if (ultimo_pos == tamanho - 1)
        {
            std::cout << "Fila cheia." << std::endl;
            return;
        }
        valor[++ultimo_pos] = cliente;
    }

    bool is_empty()
    {
        if (ultimo_pos > -1) return false;
        std::cout << "Lista vazia" << std::endl;
        return true;
    }

    void remove()
    {
        if (!is_empty())
        {
            for (int i=0; i<tamanho-1; ++i)
            {
                valor[i] = valor[i+1];
            }
            ultimo_pos--;
        }
    }

    T ultimo()
    {
        return valor[ultimo_pos];
    }

    T primeiro()
    {
        return valor[0];
    }
};

#endif // FILA_H