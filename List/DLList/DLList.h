//
// Created by Amo on 2022/11/10.
//

#ifndef MYDSLEARNING_DLLIST_H
#define MYDSLEARNING_DLLIST_H
#include <utility>

template<typename T>
class DLList {
private:
    /** Basic Node structure. */
    struct Node {
        T item;
        Node * prev;
        Node * next;

        Node(T itm, Node * p, Node * n)
        : item(itm), prev(p), next(n) {
            // empty;
        }

        Node(Node * p, Node * n)
        : prev(p), next(n) {
            // empty.
        }
    };

public:
    class ConstIterator {

        ConstIterator()
        : currentNode_(nullptr), lst_(nullptr) {
            // empty.
        }

        ConstIterator(Node * currentNode, const DLList * lst)
        : currentNode_(currentNode), lst_(lst) {
            // empty.
        }

        // Const indirectly access operator.
        const T & operator *() const {
            return retrieve();
        }

        // prefix self-increment operator
        ConstIterator & operator++() {
            currentNode_ = currentNode_->next;
            return *this;
        }

        // postfix self-increment operator
        ConstIterator operator++(int) {
            ConstIterator oldItr = *this;
            ++(*this);

            return oldItr;
        }

        // prefix self-decrement operator
        ConstIterator & operator--() {
            currentNode_ = currentNode_->prev;
            return *this;
        }

        // postfix self-decrement operator
        ConstIterator operator--(int) {
            ConstIterator oldItr = *this;
            --(*this);

            return oldItr;
        }

        // equality operator
        bool operator ==(const ConstIterator & rhs) const {
            return rhs.currentNode_ == currentNode_;
        }

        // inequality operator
        bool operator !=(const ConstIterator & rhs) const {
            return !(rhs == *this);
        }


    protected:
        T & retrieve() const {
            return currentNode_->item;
        }

        bool assertIsValid() const {
            if (currentNode_ == nullptr || lst_ == nullptr || currentNode_ == lst_->sentinel_) {
                throw "currentNode_ miss-matched. ";
            }
            return true;
        }

    protected:
        Node * currentNode_;
        const DLList * lst_;

        friend class DLList;
    };

    class Iterator : public ConstIterator {
    public:
        Iterator()
        : ConstIterator() {
            // empty
        }

        // indirectly access operator
        T & operator*() {
            return ConstIterator::retrieve();
        }

        // prefix self-increment operator.
        Iterator operator++() {
            this->currentNode_ = this->currentNode_->next;
            return *this;
        }

        // postfix self-increment operator.
        Iterator operator++(int) {
            Iterator oldItr = *this;
            ++(*this);

            return oldItr;
        }

        // prefix self-decrement operator.
        Iterator operator--() {
            this->currentNode_ = this->currentNode_->prev;
            return *this;
        }

        // postfix self-decrement operator.
        Iterator operator--(int) {
            Iterator oldItr = *this;
            ++(*this);

            return oldItr;
        }

    protected:
        Iterator(Node * currentNode, DLList * lst)
        : ConstIterator(currentNode, lst) {
            // empty
        }

        bool assertIsValid() const {
            return ConstIterator::assertIsValid();
        }

        friend class DLList;
    };

public:
    DLList() {
        init();
    }

    /** Copy constructor. */
    DLList(const DLList & rhs) {
        init();
        for (auto & item : rhs)
            pushBack(item);
    }

    /** Copy assignment. */
    DLList & operator=(const DLList & rhs) {
        if (rhs == *this)
            return *this;

        DLList copy = rhs;
        std::swap(copy, *this);

        return *this;
    }

    /** Move constructor. */
    DLList(DLList && rhs) noexcept
    : sentinel_(rhs.sentinel_), size_(rhs.size_) {
        rhs.sentinel_ = nullptr;
        rhs.size_ = 0;
    }

    /** Move assignment. */
    DLList & operator=(DLList && rhs) noexcept {
        if (*this == rhs)
            return *this;

        clear();
        delete sentinel_;
        std::exchange(sentinel_, rhs.sentinel_, nullptr);
        std::exchange(size_, rhs.size_, 0);

        return *this;
    }

    /** Clear the list. */
    void clear() {
        for (;isEmpty();)
            popBack();
    }

    ConstIterator begin() const {
        return new ConstIterator(sentinel_->next, this);
    }

    Iterator begin() {
        return new Iterator(sentinel_->next, this);
    }

    ConstIterator end() const {
        return new ConstIterator(sentinel_->prev, this);
    }

    Iterator end() {
        return new Iterator(sentinel_->prev, this);
    }

    /** Insert a new node before the iterator.
     *  @return an iterator points at the new node. */
    Iterator insert(Iterator itr, const T & item) {
        itr.assertIsValid();
        assertListPointerValid(itr);

        insert(itr.currentNode_, item);

        // update invariants.
        size_++;

        Iterator newItr(itr.currentNode_->prev, this);
        return newItr;
    }

    /** Insert a new node before the iterator.
     *  @return an iterator points at the new node. */
    Iterator insert(Iterator itr, T && item) {
        itr.assertIsValid();
        assertListPointerValid(itr);

        insert(itr.currentNode_, std::move(item));


        Iterator newItr(itr.currentNode_->prev, this);
        return newItr;
    }

    /** Remove the node that iterator points at.
     * @return an iterator points at the previous node. */
    Iterator remove(Iterator itr) {
        itr.assertIsValid();
        assertListPointerValid(itr);

        Iterator prevItr = itr;
        prevItr--;

        remove(itr.currentNode_);


        return prevItr;
    }

    const bool isEmpty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

    void pushFront(const T & item) {
        insert(sentinel_->next, item);
    }

    void pushFront(T && item) {
        insert(sentinel_->next, std::move(item));
    }

    void pushBack(const T & item) {
        insert(sentinel_, item);
    }

    void pushBack(T && item) {
        insert(sentinel_, item);
    }

    void popFront() {
        if (isEmpty())
            return; // if the list is empty, do nothing.
        remove(sentinel_->next);
    }

    void popBack() {
        if (isEmpty())
            return; // if the list is empty, do nothing.
        remove(sentinel_->prev);
    }

private:
    /** sentinel.next always points to (if exists) the first node of the list.
     *  sentinel.prev always points to (if exists) the last node of the list.
     *  loop sentinel structure. */
    Node * sentinel_;

    /** size_ always equals to the number of items in the DLList. */
    int size_;

    void init() {
        size_ = 0;

        sentinel_ = new Node(sentinel_, sentinel_);
    }

    // assert if itr 's List pointer valid.
    bool assertListPointerValid(ConstIterator itr) const {
        if (itr.lst_ != this) {
            throw "List pointer miss-matched.";
        }
        return true;
    }

    bool assertListPointerValid(Iterator itr) const {
        if (itr.lst_ != this) {
            throw "List pointer miss-matched.";
        }
        return true;
    }

    // internal insert method with node.
    void insert(Node * currentNode, const T & item) {
        currentNode->prev = new Node(item, currentNode->prev, currentNode);
        currentNode->prev->prev->next = currentNode->prev;

        // update invariants.
        size_++;
    }

    // internal insert method with node.
    void insert(Node * currentNode, T && item) {
        currentNode->prev = new Node(std::move(item), currentNode->prev, currentNode);
        currentNode->prev->prev->next = currentNode->prev;

        // update invariants.
        size_++;
    }

    // internal remove method with node.
    void remove(Node * currentNode) {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;

        delete currentNode;

        // update invariants.
        size_--;
    }
};

#endif //MYDSLEARNING_DLLIST_H
