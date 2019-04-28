#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return x*x;
}

double useRectangles(double left, double right, double numberOfRectangles) {
    double sum = 0.0;
    double delta = (right - left)/numberOfRectangles;
    while(right > left) {
        double height = abs(f(left));
        double width = delta;
        sum += height * width;
        left += delta;
    }
    return sum;
}

double useTrapezoids(double left, double right, double numberOfTrapezoids) {
    double sum = 0.0;
    double delta = (right - left)/numberOfTrapezoids;
    while(right > left) {
        double a = abs(f(left));
        double b = abs(f(left + delta));
        double h = delta;
        sum += (a+b) * h / 2.0;
        left += delta;
    }
    return sum;
}

int main() {
    int precision = 100000000;
    cout << "Using rectangles: " << setprecision(100) << useRectangles(0.0, 3.0, precision) << "\n";
    cout << "Using trapezoids: " << setprecision(100) << useTrapezoids(0.0, 3.0, precision) << "\n";
    return 0;
}