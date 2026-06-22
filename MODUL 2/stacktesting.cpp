#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack s;
    init(&s);

    cout << "Stack Testing" << endl;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    cout << "Top saat ini: " << peek(&s) << endl;

    pop(&s);
    cout << "Top setelah pop: " << peek(&s) << endl;

    push(&s, 40);
    cout << "Top setelah push 40: " << peek(&s) << endl;

    pop(&s);
    pop(&s);
    pop(&s);

    try {
        pop(&s);
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}