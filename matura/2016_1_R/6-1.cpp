#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string cipher(string str, int k) {
    k = k % 26;
    string result = "";
    //* 65 - 90
    for(int i = 0; i < str.size(); i++) {
        int newChar = (int)str[i] - 65;
        newChar += k;
        newChar = newChar % 26;
        result += (char)(newChar + 65);
    }
    return result;
}

int main() {
    fstream file;
    vector<string> ciphered;
    int k = 107;
    file.open("dane_6_1.txt", ios::in);
    if(file.is_open()) {
        for(int i = 0; i < 100; i++) {
            string temp;
            file >> temp;
            ciphered.push_back(cipher(temp, k));
        }
    }
    file.close();

    file.open("wyniki_6_1.txt", ios::out);
    if(file.is_open()) {
        for(int i = 0; i < ciphered.size(); i++) {
            file << ciphered[i] << "\n";
        }
    }
    file.close();

    return 0;
}