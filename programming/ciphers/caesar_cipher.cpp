#include <iostream>
#include <string>

using namespace std;

string caesar(string input, int key) {
    string result = "";
    for(int i = 0; i < input.size(); i++) {
        char letter = input[i];

        key = key % (90 - 65 + 1);
        int newLetter = (int)letter + key;
        
        if(newLetter > 90) {
            newLetter = 64 + (newLetter - 90);
        } else if (newLetter < 65) {
            newLetter = 91 - (65 - newLetter);
        }
        result += (char)newLetter;
    }
    return result;
}

int main() {
    //* A - 65
    //* Z - 90
    string input;
    int key;
    cout << "Enter word: ";
    cin >> input;
    cout << "Enter key: ";
    cin >> key;
    cout << "Ciphered text: " << caesar(input, key) << "\n";
}