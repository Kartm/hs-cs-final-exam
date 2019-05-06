#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct point {
    double x;
    double y;
};

double distance(point a, point b) {
    double x = pow((a.x - b.x), 2);
    double y = pow((a.y - b.y), 2);
    return sqrt(x + y);
}

int main() {
    point a = {1.0, 0.0};
    point b = {2.0, 1.0};
    cout << setprecision(10) << distance(a, b);
    return 0;
}