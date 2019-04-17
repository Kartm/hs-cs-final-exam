#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> findMinMax(vector<vector<int> > pixels) {
    int min = 255;
    int max = 0;
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 320; j++) {
            int pixel = pixels[i][j];
            if(pixel > max) max = pixel;
            else if (pixel < min) min = pixel;
        }
    }
    return make_pair(min, max);
}

bool hasSymmetry(vector<int> line) {
    int left = 0;
    int right = 320 - 1;
    while(right > left) {
        if(line[left] != line[right]) return false;
        left++;
        right--;
    }
    return true;
}

int minimalToRemove(vector<vector<int> > pixels) {
    int counter = 0;
    for(int line = 0; line < 200; line++) {
        if(hasSymmetry(pixels[line]) == false) counter++;
    }
    return counter;
}

bool hasContrastingNeighbours(int line, int column, vector<vector<int> > pixels) {
    int value = pixels[line][column];
    int neighborValue;
    if(line - 1 > 0) {
        neighborValue = pixels[line - 1][column];
        if(abs(value - neighborValue) > 128) return true;
    }
    if(line + 1 < 200) {
        neighborValue = pixels[line + 1][column];
        if(abs(value - neighborValue) > 128) return true;
    }
    if(column - 1 > 0) {
        neighborValue = pixels[line][column - 1];
        if(abs(value - neighborValue) > 128) return true;
    }
    if(column + 1 < 320) {
        neighborValue = pixels[line][column + 1];
        if(abs(value - neighborValue) > 128) return true;
    }
    return false;
}

int countPixelsWithContrastingNeighbours(vector<vector<int> > pixels) {
    int counter = 0;
    for(int line = 0; line < 200; line++) {
        for(int column = 0; column < 320; column++) {
            if(hasContrastingNeighbours(line, column, pixels)) counter++;
        }
    }
    return counter;
}

int longestVerticalLine(vector<vector<int> > pixels) {
    int column = 0;
    int maxLength = 0;
    while(column < 320) {
        vector<pair<int, int> > occurrences(255);
        for(int line = 0; line < 200; line++) {
            int number = pixels[line][column];
            pair<int, int> data = occurrences[number];
            data.first = data.first + 1;
            data.second = number;
            occurrences[number] = data;
        }
        sort(occurrences.begin(), occurrences.end());
        //cout << occurrences[254].first << " " << occurrences[254].second << "\n";
        if(occurrences[254].first > maxLength) maxLength = (int)occurrences[254].first;
        column++;
    }
    return maxLength;
}

int main() {
    fstream file;
    vector<vector<int> > pixels (200, vector<int>(320));
    file.open("dane.txt", ios::in | ios::out);
    for(int w = 0; w < 200*320; w++) {
        int line = w/320;
        int column = w % 320;

        int pixel;
        file >> pixel;
        pixels[line][column] = pixel;
    }
    //cout << "a) " << findMinMax(pixels).first << " " << findMinMax(pixels).second << "\n";
    //cout << "b) " << minimalToRemove(pixels) << "\n";
    //cout << "c) " << countPixelsWithContrastingNeighbours(pixels) << "\n";
    cout << "d) " << longestVerticalLine(pixels) << "\n";
    file.close();
    return 0;
}