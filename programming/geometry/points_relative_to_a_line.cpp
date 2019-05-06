#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
};

double evaluateLine(double A, double B, double C, double x, double y) {
    return A*x + B*y - C;
}

int position(point a, double A, double B, double C) {
    double val = evaluateLine(A, B, C, a.x, a.y);
    if(val < 0) {
        return -1; //* the point is under the line
    } else if (val > 0) {
        return 1; //* the point is above the line
    } else {
        return 0; //* the point is on the line
    }
}

int main() {
    point a = {1.0, 1.0};

    //*general form for the equation of a line
    //*Ax + By + C = 0;
    double A = -3;
    double B = 4;
    double C = 3;
    cout << position(a, A, B, C);
    return 0;
}