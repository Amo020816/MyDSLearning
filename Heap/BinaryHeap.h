//
// Created by Amo on 2022/11/12.
//

#ifndef MYDSLEARNING_HEAP_H
#define MYDSLEARNING_HEAP_H

#include<vector>
#include<utility>

template<typename T>
class BinaryHeap {
public:
    // interface.

    explicit BinaryHeap(int capacity = 100)
    : array_(capacity), size_(0) {
        // empty.
    }

    explicit BinaryHeap(const std::vector<T> & items)
    : array_(items.size() + 10), size_(items.size()) {
        for (int i = 0; i < items.size(); i++)
            array_[i + 1] = items[i];
        buildHeap();
    }

    /**
     * Insert an item, allowing duplicate.
     */
     void insert(const T & item) {
         if (size_ == array_.size() - 1)
             array_.resize(size_ * 2);

         int hole = size_ + 1;
         T copy = item;

         for (;item < array_[hole / 2]; hole /= 2)
             array_[hole] = std::move(array_[hole / 2]);

         array_[hole] = std::move(copy);

         // update invariants.
         size_++;
     }

     /**
      * Delete the minimum item in the heap.
      */
     void deleteMin() {
        if (isEmpty())
            return;

        array_[1] = std::move(array_[size_ - 1]);
         percolateDown(1);

        size_--;
     }

     /**
      * Get a const reference of the minimum.
      */
     const T & getMin() const {
         if (!isEmpty())
             return array_[1];
     }

     /**
      * Return true if the heap is empty.
      */
     bool isEmpty() const {
         return size_ == 0;
     }

private:
    // Internal methods.

    /**
     *  Establish heap order property from an arbitrary
     *  arrangement of items. Runs in linear time.
     */
    void buildHeap() {
        for (int i = size_ / 2; i > 0; i--)
            percolateDown(i);
    }

    /**
     * Internal method to percolate down a node.
     * @param node the index at which the percolation begins.
     */
    void percolateDown(int node) {
        int child;
        T temp = std::move(array_[node]);

        for (; node * 2 <= size_; node = child) {
            child = 2 * node;

            if (child <= size_ && array_[child + 1] < array_[child])
                child++;

            if (array_[child] < temp)
                array_[node] = std::move(array_[child]);
            else
                break;
        }

        array_[node] = std::move(temp);
    }

private:
    // data members.
    std::vector<T> array_;
    int size_;
};

#endif //MYDSLEARNING_HEAP_H
