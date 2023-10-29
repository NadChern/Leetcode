// LinkedList.h
// Created by Nadezhda Chernova on 10/16/23.
//

#ifndef LAB4_LINKEDLIST_H
#define LAB4_LINKEDLIST_H

#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
class LinkedList {
public:

    LinkedList();

    ~LinkedList();

    void append(T);

    void insert(T);

    void deleteNode(T);

    bool getValue(T) const;

    void getMinMaxValue(T &, T &);

    T getLastNegative() const;

    string to_string() const;
    void removeDuplicates();

    bool search(T);

    int size();

private:

    struct Node { // do i need to use template here as well?
        T data;
        Node *next;
    };
    Node *head;

    void getMinMaxValue(T &, T &, Node *); // inner function
    T getLastNegative(T, Node *) const;

    int sizeRecursive(Node *);
    void removeDuplicatesRecursive(Node * );
    bool search(Node *, T);


}; // REMEMBER SEMICOLON HERE

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node *curr;
    while (head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

template<typename T>
void LinkedList<T>::append(T value) {
    Node *curr;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

template<typename T>
void LinkedList<T>::insert(T value) {
    Node *curr;
    Node *prev;
    Node *newNode = new Node; // 1) create Node
    newNode->data = value; // 2) Initialize Node with data and next pointer
    newNode->next = nullptr;

    if (head == nullptr) { // if list is empty
        head = newNode; // set head pointer to newNode
    } else {                       // adding in ascending order
        prev = nullptr;
        curr = head;
        while (curr != nullptr && curr->data < value) { // while data < value
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr) {
            head = newNode;
            newNode->next = curr;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

template<typename T>
void LinkedList<T>::deleteNode(T value) {
    Node *prev;
    Node *curr;

    if (head != nullptr) { // we can delete smth if is not empty
        if (head->data == value) {
            curr = head;
            head = head->next;
            delete curr;
        } else {
            curr = head;
            while (curr != nullptr && curr->data != value) {
                prev = curr;
                curr = curr->next;
            }
            if (curr != nullptr) { // delete only if value is in the list
                prev->next = curr->next;
                delete curr;
            }
        }
    }
}

template<typename T>
string LinkedList<T>::to_string() const {
    stringstream ss;
    Node *curr = head;
    while (curr != nullptr) {
        ss << curr->data << " ";
        curr = curr->next;
    }
    ss << "\n";
    return ss.str();
}

template<typename T>
bool LinkedList<T>::getValue(T value) const { // remember to put const!!!
    Node *curr;
    if (head != nullptr) {
        if (head->data == value)
            return true;
        else {
            curr = head;
            while (curr != nullptr) {
                if (curr->data == value) {
                    return true;
                }
                curr = curr->next;
            }
        }
    }
    return false;
}

template<typename T>
void LinkedList<T>::getMinMaxValue(T &min, T &max) {

    if (head != nullptr) {
        min = head->data;
        max = head->data;
        getMinMaxValue(min, max, head->next);
    }
}

template<typename T>
void LinkedList<T>::getMinMaxValue(T &min, T &max,
                                   Node *ptr) { // inner function!!! of STRUCT
    if (ptr != nullptr) {
        if (ptr->data < min)
            min = ptr->data;
        else if (ptr->data > max)
            max = ptr->data;
        getMinMaxValue(min, max, ptr->next);
    }
}


template<typename T>
T LinkedList<T>::getLastNegative() const {
    Node *curr = head;
    if (head == nullptr) {
        return 0;
    }
    T lastN = getLastNegative(curr->data, curr->next);
    return lastN;
}

template<typename T>
T LinkedList<T>::getLastNegative(T last, Node *ptr) const {
    if (ptr == nullptr) {
        return (last < 0) ? last : 0; // base case
    }

    if (ptr->data < 0) {
        last = ptr->data;
    }
    return getLastNegative(last, ptr->next);
}


template<typename T>
bool LinkedList<T>::search(T target) {
    return search(head, target);
}

template<typename T>
bool LinkedList<T>::search(Node *ptr, T target) {
    if (ptr == nullptr) {
        return false;
    }
    if (ptr->data == target) {
        return true;
    }

    if (ptr->data > target) {
        return false;
    }
    return search(ptr->next, target);
}

template<typename T>
int LinkedList<T>::size() {
    return sizeRecursive(head);
}

template<typename T>
int LinkedList<T>::sizeRecursive(Node *node) {
    if (node == nullptr) {
        return 0; // Base case: an empty list has size 0
    }

    return 1 + sizeRecursive(node->next);
}

//template<typename T>
//void LinkedList<T>::removeDuplicates() {
//   removeDuplicatesRecursive(head);
//}
//
//template<typename T>
//void LinkedList<T>::removeDuplicatesRecursive(Node* current) {
//    if (current == nullptr || current->next == nullptr) {
//        return; // Base case: No duplicates to remove
//    }
//
//    if (current->data == current->next->data) {
//        Node* duplicate = current->next;
//        current->next = current->next->next;
//        delete duplicate;
//        removeDuplicatesRecursive(current); // Check for more duplicates with the current node
//    } else {
//        removeDuplicatesRecursive(current->next);
//    }
//}

template<typename T>
void LinkedList<T>::removeDuplicates() {
    removeDuplicatesRecursive(head);
}

template<typename T>
void LinkedList<T>::removeDuplicatesRecursive(Node* current) {
    if (!current) {
        return;
    }

    Node* runner = current;
    while (runner->next) {
        if (runner->next->data == current->data) {
            Node* duplicate = runner->next;
            runner->next = runner->next->next;
            delete duplicate;
        } else {
            runner = runner->next;
        }
    }

    removeDuplicatesRecursive(current->next);
}


#endif //LAB4_LINKEDLIST_H
