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

    //反转单链表
    void Reverse();

    //依次打印所有的数据
    void Print();

private:
    //返回指定位置的结点指针
    Node<T> *findNode(int index);

    //头结点
    Node<T> *head;

    //记录数据个数
    int size;
};

template<class T>
LinkedList<T>::LinkedList(): size(0) {
    head = NULL;
}

/**
 * 此方法用来返回单链表指定位置的结点指针，方便进行插入、删除、更新等操作
 */
template<class T>
Node<T> *LinkedList<T>::findNode(int index) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Find Error Index:" + to_string(index));
    }

    Node<T> *current = head;
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
    auto *node = new Node<T>();
    node->data = data;

    if (index == 0) {
        node->next = head;
        head = node;
    } else {
        Node<T> *pre = findNode(index - 1);
        node->next = pre->next;
        pre->next = node;
    }
    size++;
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
void LinkedList<T>::Update(int index, T data) {
    Node<T> *current = findNode(index);
    current->data = data;
}

template<class T>
void LinkedList<T>::Print() {
    Node<T> *temp = head;
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
 * 通过遍历所有结点，反转单链表
 */
template<class T>
void LinkedList<T>::Reverse() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node<T> *pre = head;
    Node<T> *current = head->next;
    Node<T> *temp;
    while (current) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }

    head->next = NULL;
    head = pre;
}

#endif //DATA_STRUCTURE_AND_ALGORITHMS_LINKED_LIST_H
