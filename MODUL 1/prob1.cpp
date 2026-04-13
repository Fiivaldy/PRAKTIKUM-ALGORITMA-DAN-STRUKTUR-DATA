#include <iostream>
#include "line.h"
#include "point.h"

using namespace std;

int main() {
    double a, b, c, px, py;
    while (cin >> a >> b >> c >> px >> py) {
        Line l = {a, b, c};
        Point p = {px, py};

        double hasil = gradient(&l, &p);
        cout << CheckPointPosition(hasil) << endl;
    }

    return 0;
}