#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

struct Node {
    char data;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList {

    Node* head = nullptr;
    Node* tail = nullptr;

    int size = 0;
    void init();
    bool is_empty();
    void add_front(char inputValue);
    void add_back(char inputValue);
    void add_idx(char inputValue, int indexPosition);
    void delete_front();
    void delete_back();
    void delete_idx(int indexPosition);
    void display();
    char get(int indexPosition);
    void set(char inputValue, int indexPosition);
    void clear();
};

#endif