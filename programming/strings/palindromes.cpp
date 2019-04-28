#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string word) {
    int l = 0;
    int r = word.size() - 1;
    while(l < r) {
        if(word[l] != word[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    vector<string> words {"test", "ania", "anna", "anninna"};
    for(int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
        if(isPalindrome(words[i])) {
            cout << "is a palindrome";
        } else {
            cout << "is not a palindrome";
        }
        cout << "\n";
    }
    return 0;
}