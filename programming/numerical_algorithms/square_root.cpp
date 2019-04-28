#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

double squareRoot(double number, double precision) {
    double x = number / 2;
    while(abs(x - number/x) > precision) {
        x = (x + number/x) / 2;
        cout << x << "\n";
        if(x * x == number) break;
    }
    return x;
}

int main() {
    double input;
    cin >> input;
    cout << setprecision(10) << squareRoot(input, 0.0000000001);
}