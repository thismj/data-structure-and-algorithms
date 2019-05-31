#include <iostream>
#include "data-structure/linked_list.h"
#include "data-structure/binary_tree.h"

using namespace std;

/**
 * 单链表测试方法
 */
void testLinkedList() {
    LinkedList<int> list;
    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);
    list.Insert(3, 4);
    list.Insert(4, 5);
    list.Insert(5, 6);
    list.Delete(4);
    list.Update(4, 99);
    list.Print();
    list.head = ReverseByRecursive(list.head);
    list.Print();
    list.head = ReverseByIterate(list.head);
    list.Print();
    list.head = ReverseByInsert(list.head);
    list.Print();
    cout << "total size: " << list.Size() << endl;
    cout << "index 3: " << list.Get(3) << endl;
}

void testBinaryTree() {
    BinaryTree<char> tree;
    //123##4##56##7##
    tree.CreateTree();
    cout << "total size: " << tree.Size() << endl;
    tree.Preorder();
    cout << endl;
    tree.InOrder();
    cout << endl;
    tree.PostOrder();
    cout << endl;
}

int main() {
//    testLinkedList();
    testBinaryTree();
}
