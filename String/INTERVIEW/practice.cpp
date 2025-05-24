#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2}, {0, 2}, {1, 1}};

    int n = nums.size(), q = queries.size();

    // Step 1: Build a list of query indices that cover each index i
    vector<vector<int>> covers(n);
    for (int i = 0; i < q; i++) {
        int l = queries[i][0], r = queries[i][1];
        for (int j = l; j <= r; j++) {
            covers[j].push_back(i);  // query i covers index j
        }
    }

    // Step 2: Collect essential queries
    unordered_set<int> essential;

    for (int i = 0; i < n; i++) {
        if (nums[i] > covers[i].size()) {
            // Not enough queries to cover nums[i]
            cout << -1 << endl;
            return 0;
        }

        // Greedily pick the first nums[i] queries covering this index
        // (Optimization possible, but this is sufficient for correctness)
        for (int k = 0; k < nums[i]; k++) {
            essential.insert(covers[i][k]);
        }
    }

    int maxRemovable = q - essential.size();
    cout << maxRemovable << endl;
    return 0;
}
