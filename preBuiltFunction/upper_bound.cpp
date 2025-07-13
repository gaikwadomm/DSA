#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 3, 3, 5, 7, 9};

    int x = 3;
    auto it = upper_bound(vec.begin(), vec.end(), x);  // Find first element > 3
    int index = it - vec.begin(); // Get index

    cout << "First element > " << x << " is at index: " << index << "\n";
    if (it != vec.end()) {
        cout << "Value: " << *it << "\n";
    } else {
        cout << "No element greater than " << x << "\n";
    }

    return 0;
}
