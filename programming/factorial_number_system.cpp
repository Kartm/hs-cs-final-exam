#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int factorial(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    return factorial(n - 1) * n;
}

string convertDecToFactorial(int number) {
    string result = "";

    int n = 1;
    while(number > 0) {
        int temp = (number % n);
        stringstream ss;
        ss << temp;
        result += ss.str();
        //cout << (number % n) << " ";
        number = number / n;
        n++;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << convertDecToFactorial(463);
}