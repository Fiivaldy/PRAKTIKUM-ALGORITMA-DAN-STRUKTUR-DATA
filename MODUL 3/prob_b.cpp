#include "double_linked_list.h"
#include <iostream>

using namespace std;
void deleteNode(DoubleLinkedList &dll, Node* target) {

    if (dll.size == 1) {
        delete target;
        dll.head = nullptr;
        dll.tail = nullptr;
        dll.size = 0;
        return;
    }

    target->prev->next = target->next;
    target->next->prev = target->prev;

    if (target == dll.head)
        dll.head = target->next;

    if (target == dll.tail)
        dll.tail = target->prev;

    delete target;
    dll.size--;
}

void swapAdjacent(DoubleLinkedList &dll, Node* a, Node* b) {
    if (b->next == a) {
        Node* temp = a;
        a = b;
        b = temp;
    }

    Node* before = a->prev;
    Node* after = b->next;

    before->next = b;
    b->prev = before;

    b->next = a;
    a->prev = b;

    a->next = after;
    after->prev = a;

    if (dll.head == a)
        dll.head = b;

    if (dll.tail == b)
        dll.tail = a;
}

int main() {

    DoubleLinkedList dll;
    dll.init();

    int N, R;
    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        dll.add_back(c);
    }

    Node* alpha = dll.head;
    Node* beta = dll.tail;

    for (int ronde = 0; ronde < R; ronde++) {

        long long X, Y;
        cin >> X >> Y;

        if (dll.size == 0)
            break;

        X %= dll.size;
        for (long long i = 0; i < X; i++) {
            alpha = alpha->next;
        }

        Y %= dll.size;
        for (long long i = 0; i < Y; i++) {
            beta = beta->prev;
        }

        if (alpha == beta) {

            Node* nextAlpha = alpha->next;
            Node* prevBeta = beta->prev;

            deleteNode(dll, alpha);

            if (dll.size == 0)
                break;

            alpha = nextAlpha;
            beta = prevBeta;
        }

        else if (alpha->next == beta ||
                 beta->next == alpha) {

            swapAdjacent(dll, alpha, beta);
            Node* temp = alpha;
            alpha = beta;
            beta = temp;
        }
    }

    if (dll.is_empty()) {
        cout << "KOSONG";
    }
    else {

        Node* current = dll.head;

        do {
            cout << current->data;
            current = current->next;
        }
        while (current != dll.head);
    }

    return 0;
}