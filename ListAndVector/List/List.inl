//
// Created by Amo on 2022/10/3.
//

#include "List.h"

template<typename T>
List<T>::List() {
    Init();
}

template<class T>
List<T>::~List() {
    Clear();
    delete head_;
    delete tail_;
}

template<typename T>
List<T>::List(const List<T> &rhs)
{
    Init();
    for (auto & x : rhs)
        PushBack(x);
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &rhs) {
    List copy = rhs;
    std::swap( *this, copy);
    return *this;
}

template<typename T>
List<T>::List(List<T> &&rhs)
: the_size_(rhs.the_size_), head_(rhs.head_), tail_(rhs.tail_){
    rhs.the_size_ = 0;
    rhs.head_ = nullptr;
    rhs.tail_ = nullptr;
}

template<typename T>
List<T>& List<T>::operator=(List<T> &&rhs) {
    if (&rhs == this)
        return *this;

    Clear();
    head_ = std::exchange(rhs.head_, nullptr);
    tail_ = std::exchange(rhs.tail_, nullptr);
    the_size_ = std::exchange(rhs.the_size_, 0);

    return *this;
}

template<typename T>
void List<T>::Init() {
    the_size_ = 0;
    head_ = new List<T>::Node;
    tail_ = new List<T>::Node;

    head_ -> next = tail_;
    tail_ -> prev = head_;

    head_ -> prev = nullptr;
    tail_ -> next = nullptr;

}

template<typename T>
typename List<T>::Iterator List<T>::GetBegin() {
    return head_ -> next;
}

template<typename T>
typename List<T>::ConstIterator List<T>::GetBegin() const {
    return head_ -> next;
}

template<typename T>
typename List<T>::Iterator List<T>::GetTail() {
    return tail_;
}

template<typename T>
typename List<T>::ConstIterator List<T>::GetTail() const {
    return tail_;
}

template<typename T>
int List<T>::Size() {
    return the_size_;
}

template<typename T>
bool List<T>::Empty() {
    return the_size_ == 0;
}

template<typename T>
void List<T>::Clear() {
    for (;!Empty();)
        PopFront();
}

template<typename T>
typename List<T>::Iterator List<T>::Insert(List::Iterator itr, const T &x) {
    if (!itr.AssertIsValid()) {
        return;
    }

    Node *p = itr.current_;
    the_size_++;
    Node *new_node = new Node(x, p -> prev, p);
    p -> prev -> next = new_node;
    p -> prev = new_node;
    return this;
}

template<typename T>
typename List<T>::Iterator List<T>::Insert(List::Iterator itr, T &&x) {
    if (!itr.AssertIsValid()) {
        return;
    }

    Node *p = itr.current_;
    the_size_++;
    Node *new_node = new Node(std::move(x), p -> prev, p);
    p -> prev -> next = new_node;
    p -> prev = new_node;
    return this;
}

template<typename T>
typename List<T>::Iterator List<T>::Erase(List::Iterator itr) {
    if (!itr.AssertIsValid()) {
        return;
    }

    Node *p = itr.current_;
    Iterator ret_val{ p -> next };
    p -> prev -> next = p -> next;
    p -> next -> prev = p -> prev;

    delete p;
    the_size_--;

    return ret_val;
}

template<typename T>
typename List<T>::Iterator List<T>::Erase(List::Iterator from, List::Iterator to) {
    if (!from.AssertIsValid() || to.AssertIsValid()) {
        return;
    }

    for ( Iterator itr = from; itr != to;)
        itr = Erase(itr);

    return to;
}

template<typename T>
T& List<T>::Front() {
    return head_->next->data;
}

template<typename T>
const T& List<T>::Front() const {
    return head_->next->data;
}

template<typename T>
T& List<T>::Back() {
    return tail_->data;
}

template<typename T>
const T& List<T>::Back() const {
    return tail_->data;
}

template<typename T>
void List<T>::PushFront(const T &x) {
    Insert(GetBegin()(), x);
}

template<typename T>
void List<T>::PushFront(T &&x) {
    Insert(GetBegin()(), std::move(x));
}

template<typename T>
void List<T>::PushBack(const T &x) {
    Insert(GetTail(), x);
}

template<typename T>
void List<T>::PushBack(T &&x) {
    Insert(GetTail(), std::move(x));
}

template<typename T>
void List<T>::PopFront() {
    Erase(GetBegin());
}

template<typename T>
void List<T>::PopBack() {
    Erase(GetTail() -> prev);
}


