#include <iostream>

using namespace std;

bool isRightTriangle(int a, int b, int c) {
    if(a*a + c*c == b*b) return true;
    if(a*a + b*b == c*c) return true;
    if(b*b + c*c == a*a) return true;
    return false;
} 

bool isTriangle(int a, int b, int c) {
    if(a + b <= c) return false;
    if(a + c <= b) return false;
    if(b + c <= a) return false;
    return true;
}

int main() {
    //* x*x*x + 2*x - 10;
    int a = 3;
    int b = 4;
    int c = 5;
    cout << isTriangle(a, b, c) << "\n";
    cout << isRightTriangle(a, b, c);
    return 0;
}