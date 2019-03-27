#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

stack<int> fromDec(int number, int base) {
    stack<int> result;
    while(number > 0) {
        result.push(number % base);
        number = number / base;
    }
    return result;
}

int toDec(int number, int base) {
    int result = 0;
    int n = 0;
    int length = log10(number);
    while(n <= length) {
        result += pow(base, n) * (number % 10);
        number /= 10;
        n++;
    }
    return result;
}

void printBackwards(stack<int> vec) {
    while(!vec.empty()) {
        cout << vec.top();
        vec.pop();
    }
}

int main() {
    printBackwards(fromDec(1234, 2));
    cout << "\n" << toDec(1011101, 2);
    return 0;
}