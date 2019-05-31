//
// Copyright 2019 ThisMJ.
//
// 单链表实现 c++
//
#include <iostream>

#ifndef DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H
#define DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H

using namespace std;

template<class T>
struct ListNode {
    //数据域
    T data;
    //指针域
    ListNode<T> *next;
};

/**
 * 单链表类定义
 */
template<class T>
class LinkedList {
public:
    LinkedList();

    //插入数据到指定的位置
    void Insert(int index, T data);

    //删除指定位置的数据
    void Delete(int index);

    //更新指定位置的数据
    void Update(int index, T data);

    //获取指定位置的数据
    T Get(int index);

    //返回链表数据个数
    int Size();

    //依次打印所有的数据
    void Print();

    //头结点
    ListNode<T> *head;

private:
    //返回指定位置的结点指针
    ListNode<T> *findNode(int index);

    //记录数据个数
    int size;
};

template<class T>
LinkedList<T>::LinkedList(): size(0) {
    head = nullptr;
}

/**
 * 此方法用来返回单链表指定位置的结点指针，方便进行插入、删除、更新等操作
 */
template<class T>
ListNode<T> *LinkedList<T>::findNode(int index) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Find Error Index:" + to_string(index));
    }

    ListNode<T> *current = head;
    int position = 0;
    while (position < index) {
        current = current->next;
        position++;
    }
    return current;
}

template<class T>
T LinkedList<T>::Get(int index) {
    ListNode<T> *node = findNode(index);
    return node->data;
}

template<class T>
void LinkedList<T>::Insert(int index, T data) {
    auto *node = new ListNode<T>();
    node->data = data;

    if (index == 0) {
        node->next = head;
        head = node;
    } else {
        ListNode<T> *pre = findNode(index - 1);
        node->next = pre->next;
        pre->next = node;
    }
    size++;
}

template<class T>
void LinkedList<T>::Delete(int index) {
    ListNode<T> *pre;
    ListNode<T> *current;
    if (index == 0) {
        pre = head;
    } else {
        pre = findNode(index - 1);
    }
    current = findNode(index);

    pre->next = current->next;
    delete current;
    size--;
}

template<class T>
void LinkedList<T>::Update(int index, T data) {
    ListNode<T> *current = findNode(index);
    current->data = data;
}

template<class T>
void LinkedList<T>::Print() {
    ListNode<T> *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<class T>
int LinkedList<T>::Size() {
    return size;
}

/**
 * 通过迭代方式反转单链表
 * @return 新的头结点
 */
template<class T>
ListNode<T> *ReverseByIterate(ListNode<T> *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode<T> *pre = head;
    ListNode<T> *current = head->next;
    ListNode<T> *temp;
    while (current) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }

    head->next = nullptr;
    return pre;
}

/**
 * 通过递归方式反转单链表
 * @return 新的头结点
 */
template<class T>
ListNode<T> *ReverseByRecursive(ListNode<T> *head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode<T> *current = ReverseByRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return current;
}

/**
 * 依次把后面的结点插入到头结点前面反转单链表
 * @return 新的头结点
 */
template<class T>
ListNode<T> *ReverseByInsert(ListNode<T> *head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode<T> *current = head->next;
    head->next = nullptr;
    ListNode<T> *temp;
    while (current) {
        temp = current->next;
        current->next = head;
        head = current;
        current = temp;
    }
    return head;
}

/**
 * 借助数组反转单链表（浪费空间）
 */
template<class T>
void ReverseByArray(LinkedList<T> list) {
//    if (size < 2) {
//        return;
//    }
//
//    ListNode<T> *nodeArray[size];
//    ListNode<T> *current = head;
//    int position = 0;
//    while (current) {
//        nodeArray[position] = current;
//        current = current->next;
//        position++;
//    }
//
//    for (int i = 0; i < size; ++i) {
//        if (i == 0) {
//            nodeArray[i]->next = NULL;
//        } else {
//            nodeArray[i]->next = nodeArray[i - 1];
//        }
//    }
//
//    head = nodeArray[size - 1];
}


#endif //DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H
