#ifndef VETOR_SUPER_H
#define VETOR_SUPER_H

template <typename T>
class  vetor_supermercado
{
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T* buffer;

public:

    vetor_supermercado()
    {
        my_capacity = 0;
        my_size = 0;
        buffer = 0;
    }

    vetor_supermercado(unsigned int size)
    {
        my_capacity = size;
        my_size = size;
        buffer = new T[size];
    }
    
    ~vetor_supermercado()
    {
        delete[ ] buffer;
    }

    unsigned int capacity() const
    {
        return my_capacity;
    }

    unsigned int size() const
    {
        return my_size;
    }

    T& front()
    {
        return buffer[0];
    }

    T& back()
    {
        return buffer[my_size - 1];
    }

    void push_back(const T& value) 
    {
        if (my_size >= my_capacity)
            reserve(my_capacity +5);
        buffer [my_size++] = value;
    }

    void pop_back()
    {
        my_size--;
    }

    // aloca espaço na memmória
    void reserve(unsigned int capacity)
    {
        if(buffer == 0)
        {
            my_size = 0;
            my_capacity = 0;
        }    
        T* Newbuffer = new T [capacity];
        unsigned int l_size = capacity < my_size ? capacity : my_size;

        for (unsigned int i = 0; i < l_size; i++)
            Newbuffer[i] = buffer[i];

        my_capacity = capacity;
        delete[] buffer;
        buffer = Newbuffer;
    }

    void resize(unsigned int size)
    {
        reserve(size);
        my_size = size;
    }

    // faz overload dos operadores []
    T& operator[](unsigned int index)
    {
        return buffer[index];
    }  
    
    // overload do operador =
    vetor_supermercado<T>& operator=(const vetor_supermercado<T>& v)
    {
        delete[ ] buffer;
        my_size = v.my_size;
        my_capacity = v.my_capacity;
        buffer = new T [my_size];
        for (unsigned int i = 0; i < my_size; i++)
            buffer[i] = v.buffer[i];
        return *this;
    }
  
    void clear()
    {
        my_capacity = 0;
        my_size = 0;
        buffer = 0;
    }
};

#endif // VETOR_SUPER_H