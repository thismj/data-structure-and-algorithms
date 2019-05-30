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
    list.Insert(5, 6);
    list.Insert(6, 7);
    list.Insert(7, 8);
    list.Insert(8, 9);
    list.Insert(9, 10);
    list.Insert(10, 11);
    list.Insert(11, 12);
    list.Print();
    list.head = ReverseByRecursive(list.head);
    list.Print();
    list.head = ReverseByIterate(list.head);
    list.Print();
    list.head = ReverseByInsert(list.head);
    list.Print();
    return 0;
}