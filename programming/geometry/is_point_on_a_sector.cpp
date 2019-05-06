#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
};


//* matrix
bool arePointsColinear(point a, point b, point c) {
    if((c.y - a.y)*(b.x - a.x) - (b.y - a.y)*(c.x - a.x) == 0) return true;
    return false;
}

bool doesPointFitBetween(point a, point b, point c) {
    //* c.x >= min(a.x, b.x)
    if(c.x < min(a.x, b.x)) return false;
    //* c.x <= max(a.x, b.x)
    if(c.x > max(a.x, b.x)) return false;
    //* c.y >= min(a.y, b.y)
    if(c.y < min(a.y, b.y)) return false;
    //* c.y <= max(a.y, b.y)
    if(c.y > max(a.y, b.y)) return false;
    return true;
}

bool doesBelong(point a, point b, point c) {
    if(arePointsColinear(a, b, c)) {
        if(doesPointFitBetween(a, b, c)) return true;
        else return false;
    }
    return false;
}

int main() {
    point a = {0.0, 0.0};
    point b = {2.0, 2.0};
    point c = {1.0, 1.0};
    cout << doesBelong(a, b, c);
    return 0;
}