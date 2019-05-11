#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getKey(char a, char b) {
    int newA = a - 65;
    int newB = b - 65;
    if(newB - newA < 0) return newB - newA + 26;
    return newB - newA;
}

bool isWrong(string a, string b) {
    int k = getKey(a[0], b[0]);
    for(int i = 0; i < a.size(); i++) {
        if(getKey(a[i], b[i]) != k) {
            return true;
        }
    }
    return false;
}

int main() {
    fstream file;
    vector<string> wrong;
    file.open("dane_6_3.txt", ios::in);
    if(file.is_open()) {
        for(int i = 0; i < 3000; i++) {
            string a, b;
            file >> a >> b;
            if(isWrong(a, b)) {
                wrong.push_back(a);
            }
        }
    }
    file.close();

    file.open("wyniki_6_3.txt", ios::out);
    if(file.is_open()) {
        for(int i = 0; i < wrong.size(); i++) {
            file << wrong[i] << "\n";
        }
    }
    file.close();
    return 0;
}