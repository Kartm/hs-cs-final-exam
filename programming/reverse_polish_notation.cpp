#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>
#include <cmath>

using namespace std;

bool isOperand(string text) {
    if(text == "^" || text == "*" || text == "/" || text == "~" || text == "+" || text == "-" || text == "(" || text == "=") return false;
    return true;
}

bool hasHigherPrecedence(string current, stack<string> operationStack, map<string, int> &precedence) {
    string top = operationStack.top();
    if(precedence[current] > precedence[top]) return true;
    return false;
}

string convertInfixToRpn(string infix, map<string, int> &precedence) {
    string result = "";
    stack<string> operationStack;

    stringstream s(infix);
    while(!s.eof()) {
        string temp;
        s >> temp;
        if(isOperand(temp) == true) {
            result += temp;
            result += " ";
        } else if (temp == ")") {
            while(operationStack.top() != "(") {
                result += operationStack.top();
                result += " ";
                operationStack.pop();
            }
            operationStack.pop();
        } else {
            if(operationStack.empty()) {
                operationStack.push(temp);
            } else {
                if(hasHigherPrecedence(temp, operationStack, precedence)) {
                    operationStack.push(temp);
                } else {
                    while(hasHigherPrecedence(temp, operationStack, precedence) == false) {
                        result += operationStack.top();
                        result += " ";
                        operationStack.pop();
                    }
                    operationStack.push(temp);
                }
            }
        }
    }
    while(operationStack.empty() == false) {
        result += operationStack.top();
        result += " ";
        operationStack.pop();
    }
    //* removing unnecessary space from the end
    return result.substr(0, result.size() - 1);
}

int calculateRpn(string operations) {
    stack<int> numberStack;
    stringstream s(operations);

    while(!s.eof()) {
        string temp;
        s >> temp;
        if(isOperand(temp) == false) {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            if(temp == "+") numberStack.push(b + a);
            else if(temp == "-") numberStack.push(a - b);
            else if(temp == "*") numberStack.push(b * a);
            else if(temp == "/") numberStack.push(a / b);
            else if(temp == "^") numberStack.push(pow(a, b));
        } else {
            int integer = strtol(temp.c_str(), nullptr, 10);
            numberStack.push(integer);
        }
    }
    return numberStack.top();
}

int main() {
    map<string, int> precedence;
    precedence["="] = 0;
    precedence["("] = 100;
    precedence["+"] = 2;
    precedence["-"] = 2;
    precedence["*"] = 3;
    precedence["/"] = 3;
    precedence["~"] = 3;
    precedence["^"] = 4;
    string infix = "1 - 4";
    string rpn = convertInfixToRpn(infix, precedence);
    cout << "Infix notation: " << infix << "\n";
    cout << "Reverse polish notation: " << rpn << "\n";
    cout << "\nResult: " << calculateRpn(rpn);
    return 0;
}