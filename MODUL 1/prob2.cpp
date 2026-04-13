#include <iostream>
#include "circle.h"
#include "point.h"

using namespace std;

int main() {
    double cx, cy, r, px, py;

    while (cin >> cx >> cy >> r >> px >> py) {
        Circle c;
        c.centre = {cx, cy};
        c.radius = r;

        Point p = {px, py};

        double d = distance(&c, &p);
        cout << CheckPointInCircle(d, c.radius) << endl;
    }

    return 0;
}