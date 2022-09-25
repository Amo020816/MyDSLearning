//
// Created by Amo on 2022/9/22.
//

#include "Vector.h"
#include <iostream>
#include <utility>

template<typename T>
Vector<T> ::Vector (int _the_capacity)
: the_capacity_(_the_capacity + kSpareSpace)
{
    the_size_ = 0;
    data_ = new T[the_capacity_];
}

template<typename T>
Vector<T> ::Vector(const Vector<T> &rhs)
: the_capacity_(rhs.the_capacity_), the_size_(rhs.the_size_)
{
    data_ = new T[the_capacity_];
    for (int i = 0; i < the_size_; i++)
        *(data_ + i) = *(rhs.data_ + i);
}

template<typename T>
Vector<T>& Vector<T> ::operator=(const Vector<T> &rhs)
{
    Vector copy(rhs);
    std::swap( *this, copy);
    return *this;
}

template<typename T>
Vector<T> :: ~Vector()
{
    the_size_ = 0;
    the_capacity_ = 0;
    delete[] data_;
}

template<typename T>
Vector<T>::Vector(Vector<T> &&rhs)
: data_(rhs.data_), the_capacity_(rhs.the_capacity_), the_size_(rhs.the_size_)
{
    rhs.the_capacity_ = 0;
    rhs.the_size_ = 0;
    rhs.data_ = nullptr;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> &&rhs) noexcept
{
    if (&rhs == this)
        return *this;

    delete []data_;
    data_ = std::exchange(rhs.data_, nullptr);
    the_capacity_ = std::exchange(rhs.the_capacity_, 0);
    the_size_ = std::exchange(rhs.the_size_, 0);

    return *this;
}

template<typename T>
void Vector<T>::Resize(int new_size)
{
    if (new_size >= the_capacity_)
        Reserve(2 * new_size);
    the_size_ = new_size;
}

template<typename T>
void Vector<T>::Reserve(int new_capacity)
{
    if (new_capacity < the_size_)
    {
        std::cout << "May cause data loss!\n";
        return;
    }
    T *new_data = new T[new_capacity];
    for (int i = 0; i < the_size_; i++)
        new_data[i] = std::move(data_[i]);

    the_capacity_ = new_capacity;
    std::swap(data_, new_data);
    delete []new_data;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
    return data_[index];
}

template<typename T>
const T& Vector<T>::operator[](int index) const
{
    return data_[index];
}

template<typename T>
void Vector<T>::PushBack(const T &x)
{
    if (the_size_ >= the_capacity_)
        Reserve(2 * the_capacity_ + 1);
    data_[the_size_++] = x;
}

template<typename T>
void Vector<T>::PushBack(T &&x)
{
    if (the_size_ >= the_capacity_)
        Reserve(2 * the_capacity_ + 1);
    data_[the_size_++] = std::move(x);
}

