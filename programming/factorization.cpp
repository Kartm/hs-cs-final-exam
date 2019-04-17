#include <iostream>
#include <vector>

using namespace std;

vector<int> factorize(int number) {
    vector<int> results (0);
    int divider = 2;
    while(number > 1) {
        if(number % divider == 0) {
            results.push_back(divider);
            number /= divider;
        } else {
            divider++;
        }
    }
    return results;
}

void printVector(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
    return;
}

int main() {
    int input;
    cin >> input;
    printVector(factorize(input));
    return 0;
}