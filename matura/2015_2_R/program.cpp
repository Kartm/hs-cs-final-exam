#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int a(vector<string> words) {
    int counter = 0;
    for(int i = 0; i < words.size(); i++) {
        string word = words[i];
        int count = 0;
        for(int j = 0; j < word.size(); j++) {
            if(word[j] == '0') count++;
            else count --;
        }
        if(count > 0) counter++;
    }
    return counter;
}

int b(vector<string> words) {
    int counter = 0;
    for(int i = 0; i < words.size(); i++) {
        string word = words[i];
        char currentBlock = word[0];
        int blockChangesCounter = 0;
        counter++;
        for(int j = 0; j < word.size() - 1; j++) {
            if(currentBlock != word[j+1]) {
                if(blockChangesCounter < 1) {
                    currentBlock = word[j+1];
                    blockChangesCounter++;
                } else {
                    counter--;
                    break;
                }
            }
        }
    }
    return counter;
}

int countLongestBlock(string str) {
    int longest = 0;
    int blockCounter = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '1') {
            if(blockCounter > longest) {
                longest = blockCounter;
            }
            blockCounter = 0;
        } else blockCounter++;
    }
    if(blockCounter > longest) {
        longest = blockCounter;
    }
    return longest;
}

int c(vector<string> words) {
    int longestBlock = 0;
    vector<int> linesWithLongestBlock;
    for(int i = 0; i < words.size(); i++) {
        string word = words[i];
        int longestLocalBlock = countLongestBlock(word);
        if(longestLocalBlock > longestBlock) {
            longestBlock = longestLocalBlock;
        }
    }

    for(int i = 0; i < words.size(); i++) {
        string word = words[i];
        if(countLongestBlock(word) == longestBlock) {
            cout << word << "\n";
        }
    }

    return longestBlock;
}

int main() {
    fstream file;
    vector<string> words;
    //file.open("liczby.txt", ios::in);
    file.open("slowa.txt", ios::in);
    if(file.is_open()) {
        for(int i = 0; i < 1000; i++) {
            string temp;
            file >> temp;
            words.push_back(temp);
        }
    }
    file.close();
    cout << "a) " << a(words) << "\n";
    cout << "b) " << b(words) << "\n";
    cout << "c) " << c(words) << "\n";
    return 0;
}