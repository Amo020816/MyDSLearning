#include <iostream>
#include "ArrayList/ArrayList.h"
#include "ArrayList/ArrayList.cpp"
#include "Vector/Vector.h"
#include "Vector/Vector.cpp"

using namespace std;

Vector<int> vec1;

int main()
{
    vec1.PushBack(10);
    cout << *vec1.Back() << endl;

    Vector<int> vec2(10);
    vec2.PushBack(100);
    vec2.PushBack(1000);

    vec1 = std::move(vec2);
    cout << vec1[0] << ' ' << vec1[1] << endl;

    return 0;
}
