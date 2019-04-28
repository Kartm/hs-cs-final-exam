#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int calculate(vector<int> coefficients, int x) {
    int result = coefficients[0];
    for(int i = 1; i < coefficients.size(); i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    //* x*x*x + 2*x - 10;
    vector<int> coefficients {1, 0, 2, -10};
    cout << calculate(coefficients, 10);
    return 0;
}