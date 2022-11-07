//
// Created by Amo on 2022/11/6.
//

#ifndef MYDSLEARNING_QUADRATICPROBING_H
#define MYDSLEARNING_QUADRATICPROBING_H
#include <cstddef>
#include <utility>
#include <vector>

template<typename Key>
class Hash {
public:
    size_t operator () (const Key & k) const;
};

template<typename HashObj>
class QHashTable {

public:
    explicit QHashTable( int size = 107)
    :array_(nextPrime(size)) {
        makeEmpty();
    }


    /** Make the whole table empty by setting info to EMPTY. */
    void makeEmpty() {
        size_ = 0;
        for (auto & entry : array_)
            entry.info = EMPTY;
    }

    bool contains(const HashObj & obj) const {
        return isActive(findPos(obj));
    }

    /** Insert an item into the Hash table.
     * @return return true if successfully inserted. */
    bool insert(const HashObj & obj) {
        int pos = findPos(obj);
        if (isActive(pos))
            return false;

        if (array_[pos].info == EMPTY)
            size_++;

        array_[pos].item = obj;
        array_[pos].info = ACTIVE;

        // keep the factor 0.5
        if (size_ > array_.size() / 2)
            rehash(2 * array_.size());

        return true;
    }

    /** Insert an rvalue item into the Hash table.
     *  @return true if successfully inserted. */
     bool insert(HashObj && obj) {
         int pos = findPos(obj);
         if (isActive(pos))
             return false;

         if (array_[pos].info == EMPTY)
             size_++;

         array_[pos].item = std::move(obj);
         array_[pos].info = ACTIVE;

        // keep the factor 0.5
        if (size_ > array_.size() / 2)
            rehash(2 * array_.size());

        return true;
     }

     /**
      * Remove an item from the Hash Table.
      * @param obj the target object
      * @return true if successfully deleted.
      */
     bool remove( const HashObj & obj) {
         int pos = findPos(obj);
         if (!isActive(pos))
             return false;

         array_[pos].info = DELETED;
         size_--;
         return true;
     }


    enum EntryType {
        ACTIVE, EMPTY, DELETED
    };
private:
    struct HashEntry {
        HashObj item;
        EntryType info;

        HashEntry( const HashObj & itm = HashObj(), EntryType i = EMPTY)
        : item(itm), info(i) {
            // empty
        }

        HashEntry( HashObj && itm, EntryType i = EMPTY)
        : item(std::move(itm)), info(i) {
            // empty
        }
    };

    std::vector<HashEntry> array_;

    /** size always equals to the number of the items. */
    int size_;

    /** Return if the HashEntry at pos is ACTIVE. */
    bool isActive( int pos) const {
        return array_[pos].info == ACTIVE;
    }
    /**
    * Internal method to test if a positive number is prime.
    * Not an efficient algorithm.
    */
    static bool isPrime( int n ) {
        if( n == 2 || n == 3 )
            return true;

        if( n == 1 || n % 2 == 0 )
            return false;

        for( int i = 3; i * i <= n; i += 2 )
            if( n % i == 0 )
                return false;

        return true;
    }

    /**
    * Internal method to return a prime number at least as large as n.
    * Assumes n > 0.
    */
    int nextPrime( int n ) {
        if( n % 2 == 0 )
            ++n;

        for( ; !isPrime( n ); n += 2 );

        return n;
    }

    int findPos( const HashObj & obj) const {
        int offset = 1;
        int currentPos = getHashValue(obj);

        for (;array_[currentPos].info != EMPTY &&
              array_[currentPos].item != obj;) {
            currentPos += offset;
            offset += 2;
            if (currentPos >= array_.size())
                currentPos -= array_.size();
        }

        return currentPos;
    }

    void rehash(int capability) {
        std::vector<HashEntry> oldArray = array_;
        array_.resize(nextPrime(capability));

        makeEmpty();

        for (auto & entry : oldArray)
            if (entry.info == ACTIVE )
                insert(std::move(entry.item));
    }

    size_t getHashValue( const HashObj & obj) const {
        static Hash<HashObj> hashFunction;
        return hashFunction(obj) % array_.size();
    }

};


#endif //MYDSLEARNING_QUADRATICPROBING_H
