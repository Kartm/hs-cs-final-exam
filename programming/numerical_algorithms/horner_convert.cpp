#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int convertToDec(vector<int> coefficients, int x) {
    int result = coefficients[0];
    for(int i = 1; i < coefficients.size(); i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    //* x*x*x + 2*x - 10;
    vector<int> digits {1, 0, 1};
    int base = 3;
    cout << convertToDec(digits, base);
    return 0;
}