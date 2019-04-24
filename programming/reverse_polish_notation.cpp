#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int calculateRpn(string operations) {
    stack<int> numberStack;
    stringstream s(operations);

    while(!s.eof()) {
        string temp;
        s >> temp;
        if(temp == "+") {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            a += b;
            numberStack.push(a);
        } else if (temp == "-") {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            a -= b;
            numberStack.push(a);
        } else if (temp == "*") {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            a *= b;
            numberStack.push(a);
        } else if (temp == "/") {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            a /= b;
            numberStack.push(a);
        } else {
            int integer = strtol(temp.c_str(), nullptr, 10);
            numberStack.push(integer);
        }
    }
    return numberStack.top();
}

int main() {
    string operations = "1 2 +";
    cout << calculateRpn(operations);
    return 0;
}