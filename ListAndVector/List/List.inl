//
// Created by Amo on 2022/10/3.
//

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
    if (rhs == this) {
        return *this;
    }

    List copy = rhs;
    std::swap( *this, copy);
    return *this;
}

template<typename T>
List<T>::List(List<T> &&rhs) noexcept
: the_size_(rhs.the_size_), head_(rhs.head_), tail_(rhs.tail_)  {
    rhs.the_size_ = 0;
    rhs.head_ = nullptr;
    rhs.tail_ = nullptr;
}

template<typename T>
List<T>& List<T>::operator=(List<T> &&rhs) noexcept {
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
typename List<T>::Iterator List<T>::begin() {
    Iterator itr(*this, head_);
    return ++itr;
}

template<typename T>
typename List<T>::ConstIterator List<T>::begin() const {
    ConstIterator itr(*this, head_);
    return ++itr;
}

template<typename T>
typename List<T>::Iterator List<T>::end() {
    Iterator itr(*this, tail_);
    return itr;
}

template<typename T>
typename List<T>::ConstIterator List<T>::end() const {
    ConstIterator itr(*this, tail_);
    return itr;
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
    if ( !itr.AssertIsValid()) {
        return itr;
    }

    if (itr.list_ != this) {
        std::cout << "Iterator Mismatched\n";
        return itr;
    }

    Node *p = itr.current_;
    the_size_++;
    Node *new_node = new Node(x, p -> prev, p);
    p -> prev -> next = new_node;
    p -> prev = new_node;
    return itr;
}

template<typename T>
typename List<T>::Iterator List<T>::Insert(List::Iterator itr, T &&x) {
    if ( !itr.AssertIsValid()) {
        return itr;
    }

    if (itr.list_ != this) {
        std::cout << "Iterator Mismatched\n";
        return itr;
    }

    Node *p = itr.current_;
    the_size_++;
    Node *new_node = new Node(std::move(x), p -> prev, p);
    p -> prev -> next = new_node;
    p -> prev = new_node;
    return itr;
}

template<typename T>
typename List<T>::Iterator List<T>::Erase(List::Iterator itr) {

    if ( !itr.AssertIsValid()) {
        return itr;
    }

    if (itr.list_ != this) {
        std::cout << "Iterator Mismatched\n";
        return itr;
    }

    Node *p = itr.current_;
    Iterator ret_val{ *this, p -> next };
    p -> prev -> next = p -> next;
    p -> next -> prev = p -> prev;

    delete p;
    the_size_--;

    return ret_val;
}

template<typename T>
typename List<T>::Iterator List<T>::Erase(List::Iterator from, List::Iterator to) {
    // TODO: Should check whether from is before to

    if (!from.AssertIsValid() || !to.AssertIsValid()) {
        return to;
    }

    if (from.list_ != this || to.list_ != this) {
            std::cout << "Iterator Mismatched\n";
            return to;
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
    Insert(begin(), x);
}

template<typename T>
void List<T>::PushFront(T &&x) {
    Insert(begin(), std::move(x));
}

template<typename T>
void List<T>::PushBack(const T &x) {
    Insert(end(), x);
}

template<typename T>
void List<T>::PushBack(T &&x) {
    Insert(end(), std::move(x));
}

template<typename T>
void List<T>::PopFront() {
    Erase(begin());
}

template<typename T>
void List<T>::PopBack() {
    Erase(--end());
}


