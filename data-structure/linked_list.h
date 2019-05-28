//
// Copyright 2019 ThisMJ.
//
// 单链表实现
//
#include <iostream>

#ifndef DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H
#define DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H

using namespace std;

template<class T>
struct Node {
    //数据域
    T data;
    //指针域
    Node<T> *next;
};

template<class T>
class LinkedList {
public:
    LinkedList();

    /**
     * 插入数据到指定的位置
     * @param index 指定位置
     * @param data 数据
     */
    void Insert(int index, T data);

    /**
     * 删除指定位置的数据
     * @param index 指定位置
     */
    void Delete(int index);

    /**
     * 更新指定位置的数据
     * @param index 指定位置
     * @param data 新数据
     */
    void Edit(int index, T data);

    /**
     * @param index 指定位置
     * @return 指定位置的数据
     */
    T Get(int index);

    /**
     * @return 元素总个数
     */
    int Size();

    /**
     * 依次打印所有的数据
     */
    void Print();

private:
    /**
     * @param index 指定位置
     * @return 指定位置的结点
     */
    Node<T> *findNode(int index);

    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList(): size(0) {
    head = new Node<T>;
    head->next = NULL;
}

template<class T>
Node<T> *LinkedList<T>::findNode(int index) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Find Error Index:" + to_string(index));
    }

    Node<T> *current = head->next;
    int position = 0;
    while (position < index) {
        current = current->next;
        position++;
    }
    return current;
}

template<class T>
T LinkedList<T>::Get(int index) {
    Node<T> *node = findNode(index);
    return node->data;
}

template<class T>
void LinkedList<T>::Insert(int index, T data) {
    Node<T> *pre = NULL;
    if (index == 0) {
        pre = head;
    } else {
        pre = findNode(index - 1);
    }

    if (pre != NULL) {
        auto *node = new Node<T>();
        node->data = data;
        node->next = pre->next;
        pre->next = node;
        size++;
    } else {
        throw std::invalid_argument("Insert Error Index: " + to_string(index));
    }
}

template<class T>
void LinkedList<T>::Delete(int index) {
    Node<T> *pre;
    Node<T> *current;
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
void LinkedList<T>::Edit(int index, T data) {
    Node<T> *current = findNode(index);
    current->data = data;
}

template<class T>
void LinkedList<T>::Print() {
    Node<T> *temp = head->next;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template<class T>
int LinkedList<T>::Size() {
    return size;
}


#endif //DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H
