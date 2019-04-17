#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getDividers(int number) {
    vector<int> results (0);
    int divider = 2;
    while(divider < number) {
        if(number % divider == 0) {
            results.push_back(divider);
        }
        divider++;
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
    printVector(getDividers(input));
    return 0;
}