//
// Created by Amo on 2022/9/26.
//

#ifndef LIST_H
#define LIST_H
#include <utility>
#include <iostream>

template<typename T>
class List {
    // basic structure
private:
    struct Node {
        T data;
        Node *prev, *next;

        Node(const T& d = T(), Node *p = nullptr, Node *n = nullptr)
        : data(d), prev(p), next(n) {
            // Empty
        }

        Node(T&& d, Node *p = nullptr, Node *n = nullptr)
        : data( std::move(d)), prev(p), next(n) {
            // Empty
        }

    };

    // Iterators definition
public:
    class ConstIterator
    {
    public:
        ConstIterator() : current_(nullptr) {
            // Empty
        }

        const T & operator* () const {
            return Retrieve();
        }

        ConstIterator & operator ++() {
            current_ = current_ -> next;
            return current_;
        }

        ConstIterator operator ++(int) {
            ConstIterator old = *this;
            ++( *this);
            return old;
        }

        bool operator == (const ConstIterator &rhs) {
            return current_ == rhs.current_;
        }

        bool operator != (const ConstIterator &rhs) {
            return current_ != rhs.current_;
        }

    protected:
        Node *current_;
        const List<T> *list_;

        T & Retrieve() const {
            return current_->data;
        }

        ConstIterator( const List<T>& lst, Node *p)
        : list_(lst), current_(p) {
            // Empty
        }

        bool AssertIsValid() const {
            if ((list_ == nullptr) || (current_ == nullptr) || (current_ = list_->head_)) {
                std::cout << "Iterator out of Bound" << std::endl;
                return false;
            }
            return true;
        }

        friend class List<T>;
    };

    class Iterator : public ConstIterator
    {
    public:
        Iterator()
        {};

        T & operator *() {
            return ConstIterator::Retrieve();
        }

        const T & operator *() const {
            return ConstIterator::operator*();
        }

        Iterator & operator ++() {
            this->current_ = this->current_->next;
            return *this;
        }

        Iterator operator ++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }


    protected:
        Iterator(Node *p) : ConstIterator(p) {
            // Empty
        }

        friend class List<T>;
    };

    // List functions
public:
    // constructor
    List();

    // destructor
    ~List();

    // copy constructor
    List( const List &rhs);

    // copy assignment
    List &operator = (const List &rhs);

    // move constructor
    List(List &&rhs);

    // move assignment
    List &operator = (List &&rhs);

    // -----------------------------------------------------------------------
    // Get the first element
    Iterator GetBegin();
    ConstIterator GetBegin() const;

    // Get the last element
    Iterator GetTail();
    ConstIterator GetTail() const;

    // Get Attributions
    int Size();
    bool Empty();

    // Clear the list
    void Clear();

    // insert before itr, l-value
    Iterator Insert( Iterator itr, const T & x);

    // insert before itr, r-value-reference
    Iterator Insert( Iterator itr, T && x);

    // erase item at itr
    Iterator Erase( Iterator itr);

    // erase a range
    Iterator Erase( Iterator from, Iterator to);

    T &Front();
    const T &Front() const;

    T &Back();
    const T &Back() const;

    void PushFront(const T &x);
    void PushFront(T &&x);
    void PushBack(const T &x);
    void PushBack(T &&x);

    void PopFront();
    void PopBack();

private:
    Node *head_;
    Node *tail_;
    int the_size_;

    // Initialize the list
    void Init();

};

#include "List.inl"

#endif //LIST_H
