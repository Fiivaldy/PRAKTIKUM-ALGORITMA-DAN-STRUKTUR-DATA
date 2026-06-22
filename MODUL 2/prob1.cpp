#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main() {
    int n;
    cin >> n;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        if (x == "+" || x == "-" || x == "*" || x == "/") {

            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);

            int hasil;

            if (x == "+") hasil = a + b;
            else if (x == "-") hasil = a - b;
            else if (x == "*") hasil = a * b;
            else if (x == "/") hasil = a / b;

            push(&s, hasil);

        } else {
            push(&s, stoi(x));
        }
    }

    cout << peek(&s) << endl;

    return 0;
}