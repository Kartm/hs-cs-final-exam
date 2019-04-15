#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long GCD(long long a, long long b) {
    if(b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    int gcd = GCD(a, b);
    if(gcd != 0) {
        return abs(a * b)/gcd;
    } else {
        return 0;
    }
}

int main() {
    cout << LCM(15, 40);
    return 0;
}