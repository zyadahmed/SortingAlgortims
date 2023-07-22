//
// Created by ziad on 7/19/23.
//

#ifndef SORTINGALGORTHIMS_INSERTIONSORTLIST_H
#define SORTINGALGORTHIMS_INSERTIONSORTLIST_H
#include <iostream>
using namespace  std;
template <class T>
        struct Node{
            T data;
            Node<T> * next;
        };
template <class T>
class InsertionSortList {
public:
    InsertionSortList() {
        head = nullptr;
    }

    void push(const T &item) {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T> *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sort() {
        Node<T> *lastOrder = head;
        if (head == nullptr || head->next == nullptr) {
            return;
        } else {
            while (lastOrder->next) {
                Node<T> *firstUnOrder = lastOrder->next;
                if (firstUnOrder->data < head->data) {
                    lastOrder->next = firstUnOrder->next;
                    firstUnOrder->next = head;
                    head = firstUnOrder;
                } else {
                    Node<T> *current = head->next;
                    Node<T> *previous = head;
                    while (current && current->data < firstUnOrder->data) {
                        previous = current;
                        current = current->next;
                    }
                    if (current != firstUnOrder) {
                        lastOrder->next = firstUnOrder->next;
                        firstUnOrder->next = current;
                        previous->next = firstUnOrder;
                    } else {
                        lastOrder = lastOrder->next;
                    }
                }
            }
        }
    }

private:
    Node<T> *head;
};


#endif //SORTINGALGORTHIMS_INSERTIONSORTLIST_H
