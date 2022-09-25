//
// Created by Amo on 2022/9/22.
//

#ifndef MYDSLEARNING_VECTOR_H
#define MYDSLEARNING_VECTOR_H

template<typename T>
class Vector
{
public:

    // constructor
    Vector(int _the_capacity = 0);

    // copy constructor
    Vector(const Vector &rhs);

    // copy assignment
    Vector& operator =(const Vector &rhs);

    // destructor
    ~Vector();

    // move constructor
    Vector( Vector &&rhs);

    // move assignment
    Vector& operator =(Vector&& rhs) noexcept;

    // set _the_size
    void Resize(int new_size);

    // Reserve a bigger container
    void Reserve(int new_capacity);

    T& operator [](int index);
    const T& operator[](int index) const;

    inline bool Empty() const
    { return (the_size_ == 0); }

    inline int GetSize() const
    { return the_size_; }

    inline int GetCapacity() const
    { return the_capacity_; }

    void PushBack(const T& x);
    void PushBack(T&& x);

    inline void PopBack()
    { the_size_--; }

    typedef T* Iterator;
    typedef const T *ConstIterator;

    inline Iterator Begin()
    { return &data_[0];}

    inline ConstIterator Begin() const
    { return &data_[0];}

    inline Iterator Back()
    { return &data_[GetSize() - 1];}

    inline ConstIterator Back() const
    { return &data_[GetSize() - 1];}

    const static int kSpareSpace = 16;
private:
    int the_size_;
    int the_capacity_;
    T* data_;
};

#endif //MYDSLEARNING_VECTOR_H
