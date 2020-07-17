#ifndef VETOR_SUPER_H
#define VETOR_SUPER_H

#include <iostream>

template <typename value_type>
class vetor_supermercado
{
    private:
        size_t num_elements;
        size_t total_elements;

    public:
        value_type* elements;
        /* Inicializa lista com tamanho 10 */
        vetor_supermercado() : num_elements(0), total_elements(100)
        {
            elements = new value_type[total_elements];
        }

        ~vetor_supermercado()
        {
            delete [] elements;
        }

        size_t size()     { return num_elements; }
        size_t capacity() { return total_elements; }
        
        void push_back(value_type valor)
        {
            if (num_elements + 1 > total_elements)       // dobra tamanho do vector
            {
                value_type* temp = new value_type[total_elements];
                for (size_t i=0; i<total_elements; ++i)
                {
                    temp[i] = elements[i];
                }
                delete [] elements;
                elements = nullptr;
                total_elements *= 2;
                elements = new value_type[total_elements];
                for (size_t i=0; i<total_elements; ++i)
                {
                    elements[i] = temp[i];
                }
            }
            
            elements[num_elements++] = valor;
        }
        
        void pop_back();

};

#endif // VETOR_SUPER_H