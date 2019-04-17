#include <iostream>

using namespace std;

int factorial(int number) {
    if(number == 0) return 1;
    else if (number == 1) return 1;
    else return factorial(number - 1) * number;
}

int main() {
    int input;
    cin >> input;
    cout << factorial(input);
    return 0;
}