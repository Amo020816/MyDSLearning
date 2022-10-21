//
// Created by Amo on 2022/10/9.
//

#include "List.h"

using namespace std;

int main(){
    List<int> list1;

    list1.PushBack(1);
    list1.PushBack(2);
    list1.PushBack(3);
    list1.PushBack(4);
    list1.PushBack(5);


    for(auto &item : list1) {
        std::cout << item << ' ';
    }

    List<int> lst2 = list1;

    std::cout << std::endl;

    list1.PopBack();
    list1.PopFront();

    for(auto &item : list1) {
        std::cout << item << ' ';
    }


    return 0;
};