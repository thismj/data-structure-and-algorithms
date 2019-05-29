#include <iostream>
#include "data-structure/linked_list.h"

using namespace std;

int main() {
    LinkedList<int> list;
    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);
    list.Insert(3, 4);
    list.Insert(4, 5);
    list.Print();
    list.Reverse();
    list.Print();
    return 0;
}