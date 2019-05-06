#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int change = 14;
    vector<int> coins {7, 5, 2, 1};

    vector<pair<int, int> > array (change + 1, make_pair(INT_MAX, 0));
    array[0].first = 0;

    for(int i = 0; i < coins.size(); i++) {
        int coin = coins[i];
        for(int j = 0; j < array.size(); j++) {
            int amount = j;
            if(amount % coin == 0 && amount >= coin) {
                cout << amount/coin << " vs " << array[j].first << "\n";
                if(amount / coin < array[j].first) {
                    array[j].first = amount / coin;
                    array[j].second = coin;
                }
            }
        }
    }
    
    for(int i = 0; i < array.size(); i++) {
        cout << i << " ";
    }
    cout << "\n";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i].first << " ";
    }
    cout << "\n";
    for(int i = 0; i < array.size(); i++) {
        cout << array[i].second << " ";
    }

    return 0;
}