#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; // sort based on second element
}

int main() {
    vector<vector<int>> arr = {{5, 3}, {2, 8}, {1, 4}, {9, 2}};

    sort(arr.begin(), arr.end(), comp);

    cout << "Sorted by second element:\n";
    for (auto v : arr) {
        cout << "[" << v[0] << ", " << v[1] << "]\n";
    }

    return 0;
}
