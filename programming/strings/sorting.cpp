#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string raw = "test";
    cout << raw << "\n";
    sort(raw.begin(), raw.end());
    cout << raw << "\n";
    sort(raw.begin(), raw.end(), greater<char>());
    cout << raw << "\n";
}