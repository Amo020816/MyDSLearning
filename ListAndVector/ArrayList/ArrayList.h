//
// Created by Amo on 2022/9/19.
//

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template<typename T>
class ArrayList
{
public:
    // constructor
    ArrayList(int capacity);

    ArrayList(const ArrayList&);

    ~ArrayList();

    ArrayList& operator=(const ArrayList&);

    inline int size() const
    {
        return the_size;
    }

    inline bool empty() const
    {
        return (the_size == 0);
    }

    inline bool full() const
    {
        return (the_size == K_CAPACITY);
    }

    inline bool checkIndex( int index) const
    {
        if (index < 0 || index >= the_size)
            return false;
        return true;
    }

    // insert an element into the k-th pos
    void insert( int k, const T &);

    // erase the k-th element
    void erase( int k);

    void clean();

    // return the reference of kth element
    T& get(int index) const;

private:
    T *arr;
    const int K_CAPACITY;
    int the_size;

};
#endif //ARRAY_LIST_H
