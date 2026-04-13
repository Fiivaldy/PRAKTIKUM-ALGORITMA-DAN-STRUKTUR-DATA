#include "circle.h"
#include <cmath>

double distance(const Circle *c, const Point *p) {
    return sqrt((p->x - c->centre.x) * (p->x - c->centre.x) +
                (p->y - c->centre.y) * (p->y - c->centre.y));
}

std::string CheckPointInCircle(double dist, double r) {
    if (fabs(dist - r) <= EPSILON)
        return "On Circle";
    else if (dist < r)
        return "Inside";
    else
        return "Outside";
}