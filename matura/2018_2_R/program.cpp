#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

void a(vector<pair<string, string> > &words) {
    int counter = 0;
    for(int i = 0; i < words.size(); i++) {
        string a = words[i].first;
        string b = words[i].second;
        if(a[a.size() - 1] == 'A') counter++;
        if(b[b.size() - 1] == 'A') counter++;
    }
    cout << "a) " << counter << "\n";
    return;
}

bool doesAContainB(string a, string b) {
    return a.find(b) < a.size();
}

void b(vector<pair<string, string> > &words) {
    int counter = 0;
    for(int i = 0; i < words.size(); i++) {
        string a = words[i].first;
        string b = words[i].second;
        if(doesAContainB(b, a)) counter++;
    }
    cout << "b) " << counter << "\n";
    return;
}

bool isAAnagramOfB(string a, string b) {
    map<char, int> aMap;
    map<char, int> bMap;
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++) {
        aMap[a[i]]++;
    }
    for(int i = 0; i < b.size(); i++) {
        bMap[b[i]]++;
    }
    for(int i = 0; i < b.size(); i++) {
        if(bMap[b[i]] != aMap[b[i]]) return false;
    }
    return true;
}

void c(vector<pair<string, string> > &words) {
    int counter = 0;
    for(int i = 0; i < words.size(); i++) {
        string a = words[i].first;
        string b = words[i].second;
        if(isAAnagramOfB(a, b)) counter++;
    }
    cout << "c) " << counter << "\n";
    return;
}

int main() {
    fstream file;
    vector<pair<string, string> > words;
    file.open("slowa.txt");
    if(file.is_open()) {
        for(int i = 0; i < 1000; i++) {
            string a, b;
            file >> a >> b;
            words.push_back(make_pair(a, b));
        }
    }
    file.close();

    a(words);
    b(words);
    c(words);
    return 0;
}