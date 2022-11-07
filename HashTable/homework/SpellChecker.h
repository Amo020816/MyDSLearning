//
// Created by 阿墨 on 2022/11/7.
//

#ifndef MYDSLEARNING_SPELLCHECKER_H
#define MYDSLEARNING_SPELLCHECKER_H
#include "QuadraticProbing.h"
#include <string>

class SpellChecker {

public:
    SpellChecker(int capability = 1000007);

    /** Check spelling of the file with the path sourceFile.*/
    void checkSpelling(const char * sourceFile);


private:
    /** A hash table for words. */
    QHashTable<std::string> dictionary;

    /** Initialize the dictionary from the file dictionary.txt.
     *  Calculate the hash value for each words in .txt and store it into dictionary.*/
    void buildDictionary();

    void misspelled(const std::string & misspell, int currentLine) const;

    /** List the words in the dictionary that are obtainable by adding one character. */
    void misspellAdd(const std::string & misspell) const;

    /** List the words in the dictionary that are obtainable by removing one character. */
    void misspellRemove(const std::string & misspell) const;

    /** List the words in the dictionary that are obtainable by exchanging adjacent characters. */
    void misspellExchange(const std::string & misspell) const;

    /** Return true if word is in the dictionary. */
    bool isContain(std::string word) const;

};

#endif //MYDSLEARNING_SPELLCHECKER_H
