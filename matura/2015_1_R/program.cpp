#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int a(vector<string> numbers) {
    //*how many numbers have more zeroes than ones
    int counter = 0;
    for(int i = 0; i < numbers.size(); i++) {
        string number = numbers[i];
        int value = 0;
        for(int j = 0; j < number.size(); j++) {
            if(number[j] == '0') value++;
            else value--;
        }
        if(value > 0) counter++;
    }
    return counter;
}

pair<int, int> b(vector<string> numbers) {
    //*how many numbers divisible by 2 and how many numbers divisible by 8
    int divByTwo = 0, divByEight = 0;
    for(int i = 0; i < numbers.size(); i++) {
        string number = numbers[i];
        if(number[number.size() - 1] == '0') divByTwo++;
        if(number.size() >= 3) {
            divByEight++;
            for(int j = number.size() - 1; j > (number.size() - 4); j--) {
                if(number[j] == '1') {
                    divByEight--;
                    break;
                }
            }
        }
    }

    return make_pair(divByTwo, divByEight);
}

bool isFirstGreater(string a, string b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != '1' || b[i] != '1') {
            if(a[i] == '1') return true;
            return false;
        }
    }
}

pair<int, int> c(vector<string> numbers) {
    int minimumLine = -1, maximumLine = -1;
    int minimumLength = 250;
    string minimum = "";
    int maximumLength = 0;
    string maximum = "";
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i].size() > maximumLength) {
            maximumLength = numbers[i].size();
            maximumLine = i;
            maximum = numbers[i];
        } else if (numbers[i].size() == maximumLength) {
            if(isFirstGreater(numbers[i], maximum)) {
                maximumLength = numbers[i].size();
                maximumLine = i;
                maximum = numbers[i];
            }
        }
        
        if(numbers[i].size() < minimumLength) {
            minimumLength = numbers[i].size();
            minimumLine = i;
            minimum = numbers[i];
        } else if (numbers[i].size() == minimumLength) {
            if(isFirstGreater(minimum, numbers[i])) {
                minimumLength = numbers[i].size();
                minimumLine = i;
                minimum = numbers[i];
            }
        }
    }

    return make_pair(minimumLine, maximumLine);
}

int main() {
    fstream file;
    vector<string> numbers;
    //file.open("liczby.txt", ios::in);
    file.open("liczby.txt", ios::in);
    if(file.is_open()) {
        for(int i = 0; i < 1000; i++) {
            string temp;
            file >> temp;
            numbers.push_back(temp);
        }
    }
    file.close();
    cout << "a) " << a(numbers) << "\n";
    cout << "b) by 2: " << b(numbers).first << ", by 8: " << b(numbers).second << "\n";
    cout << "c) minimum line: " << c(numbers).first + 1 << ", maximum line: " << c(numbers).second + 1 << "\n";
    return 0;
}