#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool areAnagrams(string a, string b) {
    vector<int> occurencesA (128, 0);
    vector<int> occurencesB (128, 0);
    for(int i = 0; i < a.size(); i++) {
        int asciiCode = a[i];
        occurencesA[asciiCode]++;
    }
    for(int i = 0; i < b.size(); i++) {
        int asciiCode = b[i];
        occurencesB[asciiCode]++;
    }
    for(int i = 0; i < 128; i++) {
        if(occurencesA[i] != occurencesB[i]) return false;
    }
    return true;
}

int main() {
    cout << areAnagrams("test", "stet");
    return 0;
}