#ifndef SORTINGALGORTHIMS_MERGESORTIST_H
#define SORTINGALGORTHIMS_MERGESORTIST_H

#include <iostream>

using namespace  std;
/*template <class T>
struct Node{
    T data;
    Node<T> * next;
};*/

template <class T>
class MergeSortist {
public:
    MergeSortist() : head(nullptr) {}

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
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void sort() {
        MergeRecursive(head);
    }

private:
    void divide(Node<T> *first, Node<T> *&first1, Node<T> *&first2) {
        Node<T> *middle = nullptr;
        Node<T> *current = nullptr;
        if (first == nullptr) {
            first1 = nullptr;
            first2 = nullptr;
        } else if (first->next == nullptr) {
            first1 = first;
            first2 = nullptr;
        } else {
            middle = first;
            current = first->next;
            if (current != nullptr) {
                current = current->next;
            }
            while (current != nullptr) {
                middle = middle->next;
                current = current->next;
                if (current != nullptr) {
                    current = current->next;
                }
            }
            first1 = first;
            first2 = middle->next;
            middle->next = nullptr;
        }
    }

    Node<T> *mergelists(Node<T> *first1, Node<T> *first2) {
        Node<T> *newhead = nullptr;
        Node<T> *currentNew = nullptr;
        if (first1 == nullptr) {
            return first2;
        } else if (first2 == nullptr) {
            return first1;
        } else {
            if (first1->data < first2->data) {
                newhead = first1;
                first1 = first1->next;
                currentNew = newhead;
            } else {
                newhead = first2;
                first2 = first2->next;
                currentNew = newhead;
            }
            while (first1 != nullptr && first2 != nullptr) {
                if (first1->data < first2->data) {
                    currentNew->next = first1;
                    currentNew = currentNew->next;
                    first1 = first1->next;
                } else {
                    currentNew->next = first2;
                    currentNew = currentNew->next;
                    first2 = first2->next;
                }
            }
            if (first1 == nullptr) {
                currentNew->next = first2;
            } else {
                currentNew->next = first1;
            }
        }
        return newhead;
    }

    void MergeRecursive(Node<T> *&head) {
        Node<T> *otherhead = nullptr;
        if (head != nullptr) {
            if (head->next != nullptr) {
                divide(head, head, otherhead);
                MergeRecursive(head);
                MergeRecursive(otherhead);
                head = mergelists(head, otherhead);
            }
        }
    }

    Node<T> *head;
};

#endif //SORTINGALGORTHIMS_MERGESORTIST_H