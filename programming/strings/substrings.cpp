#include <iostream>
#include <string>

using namespace std;

/*
string::npos - not found
find(str, firstCharacterPosition, )
substr(firstCharacter, lengthToBeIncluded)
*/

int main() {
    string str1 = "atest";
    string str2 = "a";
    if(str1.find(str2) != string::npos) {
        cout << "found!" << "\n";
    } else {
        cout << "not found" << "\n";
    }
    if(str1.find(str2, 1) != string::npos) {
        cout << "found!" << "\n";
    } else {
        cout << "not found" << "\n";
    }

    string str3 = str1.substr(1, 2);
    cout << str3 << "\n";

    return 0;
}