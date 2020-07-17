#ifndef VETOR_SUPER_H
#define VETOR_SUPER_H

template <class T>
class  vetor_supermercado
{
public:

    // iterador para funcionar igual ao vector em loops
    typedef T* iterator;

    // construtores
    vetor_supermercado();
    vetor_supermercado(unsigned int size);
    ~vetor_supermercado();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T& front();
    T& back();
    void push_back(const T& value); 
    void pop_back();  

    void reserve(unsigned int capacity);   
    void resize(unsigned int size);   

    // overload dos []
    T& operator[](unsigned int index);  
    vetor_supermercado<T>& operator=(const vetor_supermercado<T>&);
    void clear();
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T* buffer;
};

template<class T>
vetor_supermercado<T>::vetor_supermercado()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}
/*
template<class T>
vetor_supermercado<T>::vetor_supermercado(const vetor_supermercado<T>& v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];  
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];  
}
*/
template<class T>
vetor_supermercado<T>::vetor_supermercado(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}
/*
template<class T>
vetor_supermercado<T>::vetor_supermercado(unsigned int size, const T& initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
    //T();
}
*/
template<class T>
vetor_supermercado<T>& vetor_supermercado<T>::operator = (const vetor_supermercado<T>& v)
{
    delete[ ] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T [my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
typename vetor_supermercado<T>::iterator vetor_supermercado<T>::begin()
{
    return buffer;
}

template<class T>
typename vetor_supermercado<T>::iterator vetor_supermercado<T>::end()
{
    return buffer + size();
}

template<class T>
T& vetor_supermercado<T>::front()
{
    return buffer[0];
}

template<class T>
T& vetor_supermercado<T>::back()
{
    return buffer[my_size - 1];
}

template<class T>
void vetor_supermercado<T>::push_back(const T& v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity +5);
    buffer [my_size++] = v;
}

template<class T>
void vetor_supermercado<T>::pop_back()
{
    my_size--;
}

template<class T>
void vetor_supermercado<T>::reserve(unsigned int capacity)
{
    if(buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }    
    T* Newbuffer = new T [capacity];
    //assert(Newbuffer);
    unsigned int l_Size = capacity < my_size ? capacity : my_size;
    //copy (buffer, buffer + l_Size, Newbuffer);

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template<class T>
unsigned int vetor_supermercado<T>::size()const//
{
    return my_size;
}

template<class T>
void vetor_supermercado<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template<class T>
T& vetor_supermercado<T>::operator[](unsigned int index)
{
    return buffer[index];
}  

template<class T>
unsigned int vetor_supermercado<T>::capacity()const
{
    return my_capacity;
}

template<class T>
vetor_supermercado<T>::~vetor_supermercado()
{
    delete[ ] buffer;
}
template <class T>
void vetor_supermercado<T>::clear()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

#endif // VETOR_SUPER_H