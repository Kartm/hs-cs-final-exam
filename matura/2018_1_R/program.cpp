#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void a(vector<string> data) {
    string message = "";
    for(int i = 39; i < 1000; i += 40) {
        message += data[i][9];
    }
    cout << "a) " << message << "\n";
    return;
}

int countUniqueLetters(string str) {
    char current = str[0];
    sort(str.begin(), str.end());
    int counter = 1;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] != current) {
            counter++;
            current = str[i];
        }
    }
    return counter;
}

void b(vector<string> data) {
    int longest = 0;
    for(int i = 0; i < 1000; i++) {
        int count = countUniqueLetters(data[i]);
        if(count > longest) longest = count;
    }
    for(int i = 0; i < 1000; i++) {
        int count = countUniqueLetters(data[i]);
        if(count == longest) {
            cout << "b) " << data[i] << " " << longest << "\n";
            return;
        }
    }
    return;
}

void c(vector<string> data) {
    cout << "c) \n";
    for(int i = 0; i < 1000; i++) {
        string word = data[i];
        sort(word.begin(), word.end());
        if(word[word.size() - 1] - word[0] <= 10) {
            cout << word << "\n";
        }
    }
    return;
}


int main() {
    fstream file;
    vector<string> data;
    file.open("sygnaly.txt");
    if(file.is_open()) {
        for(int i = 0; i < 1000; i++) {
            string temp;
            file >> temp;
            data.push_back(temp);
        }
    }
    file.close();

    a(data);
    b(data);
    c(data);
    return 0;
}