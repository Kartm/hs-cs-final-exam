#include <iostream>
#include <cmath>

using namespace std;

bool belongsToCircle(double a, double b, double r, double x, double y) {
    //* (x-a)^2 + (y-b) ^2 == r^2
    if(pow(x-a, 2) + pow(y-b, 2) <= pow(r, 2)) return true;
    return false;
}

int main() {
    double a = 1;
    double b = 1;
    double r = 2;

    double x = 1.5;
    double y = 1;

    cout << belongsToCircle(a, b, r, x, y);
}