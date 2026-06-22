#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue q;
    init(&q);

    cout << "Pengujian Queue" << endl;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    cout << "Front saat ini: " << front(&q) << endl;
    cout << "Rear saat ini: " << back(&q) << endl;

    dequeue(&q);
    cout << "Front setelah dequeue: " << front(&q) << endl;

    enqueue(&q, 40);
    cout << "Rear setelah enqueue 40: " << back(&q) << endl;

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    try {
        dequeue(&q);
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}