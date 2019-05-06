#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    vector<int> v;
    v.push_back(1);
    v.push_back(14);
    v.push_back(111);
    v.push_back(451);
    v.push_back(561);
    v.push_back(1233);
    v.push_back(1351);
    v.push_back(60411);

    sort(v.begin(), v.end());

    cout << binary_search(v.begin(), v.end(), 3) << "\n";
    cout << binary_search(v.begin(), v.end(), 561) << "\n";
    cout << binary_search(v.begin(), v.end(), 451) << "\n";

    //*lower_bound returns an iterator pointing to the first element in the range with value not less than
    //*upper_bound returns an iterator pointing to the first element in the range with value greater than

    vector<int>::iterator lo, up;
    lo = lower_bound(v.begin(), v.end(), 561);
    up = upper_bound(v.begin(), v.end(), 6);

    cout << *lo << '\n'; 
    cout << *up << '\n'; 

    return 0;
}