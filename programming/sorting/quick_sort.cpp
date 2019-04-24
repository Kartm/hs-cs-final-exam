#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int> &array, int from, int to) {
    if(from >= to) return;
    int value = array[to];
    int counter = from;
    for(int i = from; i < to; i++) {
        if(array[i] <= value) {
            swap(array[i], array[counter]);
            counter++;
        }
    }
    swap(array[counter], array[to]);
    quickSort(array, from, counter - 1);
    quickSort(array, counter + 1, to);
    return;
}

void printVec(vector<int> array) {
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << ' ';
    }
    cout << "\n";
}

int main() {
    vector<int> array {1, 6, 3, 2, 100, 50, 10, 2, 1};
    printVec(array);
    quickSort(array, 0, array.size() - 1);
    printVec(array);
    return 0;
}