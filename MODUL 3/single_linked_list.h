#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

struct Node {
    int data;
    Node* next;
};

struct SingleLinkedList {

    Node* head = nullptr;
    Node* tail = nullptr;

    int size = 0;

    void init();
    bool is_empty();

    void add_front(int inputValue);
    void add_back(int inputValue);
    void add_idx(int inputValue, int indexPosition);

    void delete_front();
    void delete_back();
    void delete_idx(int indexPosition);

    void display();

    int get(int indexPosition);

    void set(int inputValue, int indexPosition);

    void clear();
};

#endif