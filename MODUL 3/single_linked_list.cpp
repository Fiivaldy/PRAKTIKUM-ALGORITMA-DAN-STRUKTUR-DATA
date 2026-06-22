#include "single_linked_list.h"
#include <iostream>

using namespace std;

void SingleLinkedList::init() {

    head = nullptr;
    tail = nullptr;

    size = 0;
}

bool SingleLinkedList::is_empty() {

    return head == nullptr;
}

void SingleLinkedList::add_front(int inputValue) {

    Node* newNode = new Node;

    newNode->data = inputValue;
    newNode->next = nullptr;

    if (is_empty()) {

        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else {

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    size++;
}

void SingleLinkedList::add_back(int inputValue) {

    Node* newNode = new Node;

    newNode->data = inputValue;
    newNode->next = nullptr;

    if (is_empty()) {

        head = newNode;
        tail = newNode;

        tail->next = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    size++;
}

void SingleLinkedList::add_idx(int inputValue, int indexPosition) {
    if (indexPosition < 0 || indexPosition > size) {

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
    Node* newNode = new Node;

    newNode->data = inputValue;
    newNode->next = nullptr;

    Node* currentNode = head;

    for (int currentIndex = 0;
         currentIndex < indexPosition - 1;
         currentIndex++) {

        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;

    currentNode->next = newNode;

    size++;
}

void SingleLinkedList::delete_front() {

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
        tail->next = head;

        delete deletedNode;
    }

    size--;
}

void SingleLinkedList::delete_back() {
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

        Node* currentNode = head;
        while (currentNode->next != tail) {

            currentNode = currentNode->next;
        }
        delete tail;
        tail = currentNode;
        tail->next = head;
    }

    size--;
}
void SingleLinkedList::delete_idx(int indexPosition) {
    if (indexPosition < 0 || indexPosition >= size) {

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
         currentIndex < indexPosition - 1;
         currentIndex++) {

        currentNode = currentNode->next;
    }

    Node* deletedNode = currentNode->next;
    currentNode->next = deletedNode->next;

    delete deletedNode;

    size--;
}

void SingleLinkedList::display() {

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

int SingleLinkedList::get(int indexPosition) {
    if (indexPosition < 0 || indexPosition >= size) {

        cout << "Index tidak valid\n";
        return -1;
    }

    Node* currentNode = head;
    for (int currentIndex = 0;
         currentIndex < indexPosition;
         currentIndex++) {

        currentNode = currentNode->next;
    }

    return currentNode->data;
}

void SingleLinkedList::set(int inputValue,
                           int indexPosition) {

    if (indexPosition < 0 || indexPosition >= size) {

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
void SingleLinkedList::clear() {
    while (!is_empty()) {

        delete_front();
    }

    head = nullptr;
    tail = nullptr;

    size = 0;
}