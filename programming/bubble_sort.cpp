#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> array) {
    bool isDone = false;
    while(isDone == false) {
        //* iterating through array
        bool isSorted = true;
        for(int i = 0; i < array.size() - 1; i++) {
            if(array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp; 
                isSorted = false;
            }
        }
        isDone = isSorted;
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
    printVec(bubbleSort(array));
    return 0;
}