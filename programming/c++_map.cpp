#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> myMap;
    myMap['A'] = 0;
    myMap['X'] = 1;
    cout << myMap.size() << " " << myMap['A'] << " " << myMap['X'] << "\n";
    return 0;
}