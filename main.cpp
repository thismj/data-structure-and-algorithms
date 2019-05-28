#include <iostream>
#include "data-structure/linked_list.h"

using namespace std;

int main() {
    LinkedList<int> list;
    list.Insert(0,1);
    list.Insert(1,2);
    list.Insert(2,3);
    list.Insert(3,4);
    list.Insert(4,5);
    list.Edit(0,22);
    list.Edit(3,244);
    list.Delete(3);
    cout << "total size: " << list.Size() << endl;
    list.Print();
    cout << "0:" << list.Get(0) << endl;
    cout << "1:" << list.Get(1) << endl;
    cout << "2:" << list.Get(2) << endl;
    cout << "2:" << list.Get(3) << endl;
    return 0;
}