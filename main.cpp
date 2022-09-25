#include <iostream>
#include "ArrayList/ArrayList.h"
#include "ArrayList/ArrayList.cpp"

ArrayList<int> list1(20);

using namespace std;
int main()
{

    for (int i = 0; i < 10; i++)
        list1.insert(i, i);
    list1.insert(5, 11);
    list1.clean();
    list1.insert(0, 1100);
    for (int i = 0; i < list1.size(); i++)
        cout << list1.get(i) << ' ';
    cout << endl;

    return 0;
}
