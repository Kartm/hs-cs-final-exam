#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long a, long long b) {
    if(b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    cout << GCD(15, 40);
    return 0;
}