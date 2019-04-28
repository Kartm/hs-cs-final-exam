#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> array) {
    //* we assume that the first number is already sorted
    for(int i = 1; i < array.size(); i++) { //* starting at first unsorted element
        int j = i;
        int unsorted = array[j];
        while(j > 0 && unsorted < array[j - 1]) { //* while the unsorted element is smaller than sorted one
            array[j] = array[j - 1]; //* shifting to the right
            j--;
        }
        array[j] = unsorted;
    }
    return array;
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
    printVec(insertionSort(array));
    return 0;
}