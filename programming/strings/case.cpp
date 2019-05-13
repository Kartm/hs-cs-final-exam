#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "it will be uppercase";
    string str2 = "It WiLL Be LoWeRCaSe";
    cout << str1 << "\n" << str2 << "\n";
    string str1_2 = "";
    string str2_2 = "";
    for(int i = 0; i < str1.size(); i++) {
        str1_2 += toupper(str1[i]);
    }

    for(int i = 0; i < str2.size(); i++) {
        str2_2 += tolower(str2[i]);
    }

    cout << str1_2 << "\n" << str2_2 << "\n";
}