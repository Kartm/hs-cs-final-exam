#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str = "test";
    cout << str << "\n";
    reverse(str.begin(), str.end());
    cout << str;
}