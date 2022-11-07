//
// Created by 阿墨 on 2022/11/7.
//

#include "SpellChecker.h"
#include <string>
#include <fstream>
#include <cstddef>
#include <iostream>

template<>
class Hash<std::string>{
public:

    size_t operator () (const std::string & k) const {
        static std::hash<std::string> wordHasher;
        return wordHasher(k);
    }
};

SpellChecker::SpellChecker(int capability)
: dictionary(capability) {
    buildDictionary();
}

void SpellChecker::buildDictionary() {
    std::ifstream dic;

    dic.open("../hashtable/dictionary.txt");
    std::string word;

    for (;dic >> word;) {
        word[0] = (char) toupper(word[0]);
        dictionary.insert(word);

        word[0] = (char) tolower(word[0]);
        dictionary.insert(word);
    }
}

bool SpellChecker::isContain(std::string word) const {
    return dictionary.contains(word);
}

void SpellChecker::checkSpelling(const char *sourceFile) {
    std::ifstream src;
    src.open(sourceFile);

    std::string line, word;
    int currentLine = 0;
    for (; getline(src, line);) {
        currentLine++;
        for (char i : line) {
            if (isalpha(i))
                word += i;
            else {
                if (!isContain(word))
                    misspelled(word, currentLine);
                word.clear();
            }
        }
        if (word != "" && !isContain(word))
            misspelled(word, currentLine);
        word.clear();
    }
}

void SpellChecker::misspelled(const std::string & word, int currentLine) const {
    std::cout << word << " in line " << currentLine << " is misspelled.\n";
    std::cout << "The possible word is: \n ";
    misspellAdd(word);
    misspellRemove(word);
    misspellExchange(word);
}

void SpellChecker::misspellAdd(const std::string &misspell) const {
    for (int i = 0; i <= misspell.size(); i++) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            std::string copy = misspell;
            copy.insert(i, 1, ch);
            if (isContain(copy))
                std::cout << copy << std::endl;
        }
    }
}

void SpellChecker::misspellRemove(const std::string &misspell) const {
    for (int i = 0; i < misspell.size(); i++) {
        std::string copy = misspell;
        copy.erase(i, 1);
        if (isContain(copy))
            std::cout << copy << std::endl;
    }
}

void SpellChecker::misspellExchange(const std::string &misspell) const {
    for (int i = 0; i < misspell.size() - 1; i++) {
        std::string copy = misspell;
        std::swap(copy[i], copy[i + 1]);
        if (isContain(copy))
            std::cout<< copy << std::endl;
    }
}

