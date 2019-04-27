#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//* an example function
double f(double x) {
    return x*x*x + 2*x - 10;
}

bool sign(double x) {
    return f(x) >= 0.0;
}

double bisection(double left, double right, double precision) {
    double midpoint = (left + right) / 2;
    double midValue = f(midpoint);
    while(fabs(midValue) > precision) { //* while not satisfactory precision
        if(sign(midpoint) == sign(left)) { //*the left boundary should be of a opposite sign of the right boundary
            left = midpoint;
        } else {
            right = midpoint;
        }
        midpoint = (left + right) / 2;
        midValue = f(midpoint);
        cout << midValue << "\n";
    }
    return midpoint;
}

int main() {
    double precision = 0.0001;
    cout << setprecision(100) << bisection(-5.0, 5.0, precision) << "\n";
    return 0;
}