//
// Created by Amo on 2022/9/20.
//

#include "ArrayList.h"
#include <algorithm>
#include <iostream>

template<typename T>
ArrayList<T> :: ArrayList(int capacity)
: K_CAPACITY(capacity)
{
    arr = new T[capacity];
    the_size = 0;
}

template<typename T>
ArrayList<T> :: ArrayList(const ArrayList<T> &rhs)
: K_CAPACITY(rhs.K_CAPACITY)
{
    the_size = rhs.the_size;
    arr = new T[K_CAPACITY];
    for (int i = 0; i < the_size; i++)
        *(arr + i) = *(rhs.arr + i);
}

template<typename T>
ArrayList<T> :: ~ArrayList()
{
    delete []arr;
    the_size = 0;
}


template<typename T>
ArrayList<T>& ArrayList<T> ::  operator =(const ArrayList &rhs)
{
    ArrayList copy(rhs);
    std::swap(*this, copy);
    return *this;
}


template<typename T>
void ArrayList<T> ::insert(int k, const T &ins)
{
    if (k < 0 || k > the_size)
    {
        std::cout << "Try to insert into invalid position\n";
        return;
    }
    if (full())
    {
        std::cout << "ArrayList is already full" << std::endl;
        return;
    }
    the_size ++;
    *(arr + the_size) = ins;
    for (int i = the_size - 1; i >= k; i--)
        std::swap(*(arr + i), *(arr + i + 1));
}


template<typename T>
void ArrayList<T> ::erase(int k)
{
    if (!checkIndex(k))
    {
        std::cout << "Try to erase an invalid position\n";
        return;
    }
    if ((arr + k) == nullptr)
    {
        std::cout << "Try to erase null\n";
        return;
    }
    for (int i = k; i < the_size; i++)
        std::swap(*(arr + i), *(arr + i + 1));
    arr[--the_size].~T();
}

template<typename T>
void ArrayList<T> ::clean()
{
    for (int i = 0; i < the_size; i++)
        (arr + i)->~T();
    the_size = 0;
}

template<typename T>
T& ArrayList<T> :: get(int index) const
{
    if (!checkIndex(index))
    {
        std::cout << "The index is invalid" << std::endl;
        exit(-1);
    }
    return *(arr + index);
}
