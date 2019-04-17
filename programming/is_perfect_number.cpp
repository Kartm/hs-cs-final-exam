#include <iostream>

using namespace std;

bool isPerfectNumber(int number) {
    int originalNumber = number;
    int divider = 2;
    int sum = 1;
    while(divider < number) {
        if(number % divider == 0) sum += divider;
        divider++;
    }
    if(number == 1) return false;
    return originalNumber == sum;
}

int main() {
    int input;
    cin >> input;
    cout << isPerfectNumber(input);
    return 0;
}