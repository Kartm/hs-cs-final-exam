#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
    return;
}

vector<int> sieve(int upTo) {
    vector<int> results;
    vector<bool> isPrime(upTo + 1, true);
    for(int i = 2; i <= upTo; i++) {
        for(int j = i + i; j <= upTo; j+=i) {
            isPrime[j] = false;
        }
    }
    for(int i = 1; i <= upTo; i++) {
        if(isPrime[i] == true) {
            results.push_back(i);
        }
    }
    return results;
}

int main() {
    printVector(sieve(100));
}