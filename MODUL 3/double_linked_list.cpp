#include "double_linked_list.h"
#include <iostream>

using namespace std;
void DoubleLinkedList::init() {

    head = nullptr;
    tail = nullptr;

    size = 0;
}
bool DoubleLinkedList::is_empty() {

    return head == nullptr;
}

void DoubleLinkedList::add_front(char inputValue) {
    Node* newNode = new Node;
    newNode->data = inputValue;
    if (is_empty()) {

        newNode->next = newNode;
        newNode->prev = newNode;

        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    size++;
}

void DoubleLinkedList::add_back(char inputValue) {

    Node* newNode = new Node;

    newNode->data = inputValue;
    if (is_empty()) {

        newNode->next = newNode;
        newNode->prev = newNode;

        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    size++;
}

void DoubleLinkedList::add_idx(char inputValue,
                               int indexPosition) {
    if (indexPosition < 0 ||
        indexPosition > size) {

        cout << "Index tidak valid\n";
        return;
    }
    if (indexPosition == 0) {

        add_front(inputValue);
        return;
    }

    if (indexPosition == size) {

        add_back(inputValue);
        return;
    }

    Node* currentNode = head;
    for (int currentIndex = 0;
         currentIndex < indexPosition;
         currentIndex++) {

        currentNode = currentNode->next;
    }

    Node* newNode = new Node;

    newNode->data = inputValue;
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;

    currentNode->prev->next = newNode;
    currentNode->prev = newNode;

    size++;
}
void DoubleLinkedList::delete_front() {
    if (is_empty()) {

        cout << "Linked list kosong\n";
        return;
    }

    if (head == tail) {

        delete head;

        head = nullptr;
        tail = nullptr;
    }
    else {

        Node* deletedNode = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete deletedNode;
    }

    size--;
}
void DoubleLinkedList::delete_back() {
    if (is_empty()) {

        cout << "Linked list kosong\n";
        return;
    }
    if (head == tail) {

        delete tail;

        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* deletedNode = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;

        delete deletedNode;
    }

    size--;
}
void DoubleLinkedList::delete_idx(int indexPosition) {
    if (indexPosition < 0 ||
        indexPosition >= size) {

        cout << "Index tidak valid\n";
        return;
    }
    if (indexPosition == 0) {

        delete_front();
        return;
    }
    if (indexPosition == size - 1) {

        delete_back();
        return;
    }

    Node* currentNode = head;
    for (int currentIndex = 0;
         currentIndex < indexPosition;
         currentIndex++) {

        currentNode = currentNode->next;
    }
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;

    delete currentNode;

    size--;
}
void DoubleLinkedList::display() {
    if (is_empty()) {

        cout << "Linked list kosong\n";
        return;
    }

    Node* currentNode = head;

    cout << "Isi Linked List : ";
    do {

        cout << currentNode->data << " ";

        currentNode = currentNode->next;

    } while (currentNode != head);

    cout << endl;
}
char DoubleLinkedList::get(int indexPosition) {
    if (indexPosition < 0 ||
        indexPosition >= size) {

        cout << "Index tidak valid\n";
        return '\0';
    }

    Node* currentNode = head;
    for (int currentIndex = 0;
         currentIndex < indexPosition;
         currentIndex++) {

        currentNode = currentNode->next;
    }

    return currentNode->data;
}
void DoubleLinkedList::set(char inputValue,
                           int indexPosition) {

    if (indexPosition < 0 ||
        indexPosition >= size) {

        cout << "Index tidak valid\n";
        return;
    }

    Node* currentNode = head;
    for (int currentIndex = 0;
         currentIndex < indexPosition;
         currentIndex++) {

        currentNode = currentNode->next;
    }

    currentNode->data = inputValue;
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {

        delete_front();
    }

    head = nullptr;
    tail = nullptr;

    size = 0;
}