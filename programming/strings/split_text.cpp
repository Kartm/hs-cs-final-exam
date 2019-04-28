#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string text, char splitBy) {
    vector<string> results;
    string temp = "";
    for(int i = 0; i < text.size(); i++) {
        char letter = text[i];
        if((int)letter != (int)splitBy) {
            temp += letter;
        } else {
            results.push_back(temp);
            temp = "";
        }
    }
    results.push_back(temp);
    return results;
}

int main() {
    string originalText = "text with spaces";

    vector<string> result = split(originalText, ' ');

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}