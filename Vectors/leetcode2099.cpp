#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// 🔁 Step-by-Step Logic
// ✅ Step 1: Track Each Number with Its Original Index
// We store each number along with its position (index) in the original array, like this:

// cpp
// Copy code
// valueWithIndex.push_back({nums[i], i});
// For example, if nums = [5, 2, 9, 1], we make:

// css
// Copy code
// [(5,0), (2,1), (9,2), (1,3)]
// This way we can:

// Sort by value to find the largest numbers.

// Later, use the index to restore the original order.

// ✅ Step 2: Sort by Value (Descending)
// Now we sort these pairs in descending order (largest value first).
// Why? Because we want the k largest values.

// From the above list:

// less
// Copy code
// Before sorting:  [(5,0), (2,1), (9,2), (1,3)]
// After sorting:   [(9,2), (5,0), (2,1), (1,3)]
// ✅ Step 3: Pick the First k Elements
// We just pick the first k elements (i.e., top k values).

// If k = 2, we take:

// css
// Copy code
// [(9,2), (5,0)]
// ✅ Step 4: Sort by Original Index
// Now we must restore the original order of these selected numbers — because the subsequence must match the input order.

// So we sort based on the index part:

// css
// Copy code
// From [(9,2), (5,0)] → Sort by index → [(5,0), (9,2)]
// ✅ Step 5: Extract the Values Only
// Finally, we take just the numbers:

// csharp
// Copy code
// [5, 9]
// That’s the answer: the maximum sum subsequence of length k with elements in the original order.

// 💡 Final Notes
// We don’t need to generate all subsequences, which is very slow.

// We only pick the top k numbers with max value using sorting, and then fix the order.

// 📦 Time & Space Complexity
// Operation	Complexity
// Storing (value, index) pairs	O(n)
// Sorting by value (descending)	O(n log n)
// Picking top k elements	O(k)
// Sorting top k by index	O(k log k)
// Final extraction of values	O(k)
// Total Time	O(n log n)
// Space Used	O(n)

vector<int> maxSubsequence(vector<int>& nums, int k) {
    // Step 1: Store each number with its original index
    vector<pair<int, int>> valueWithIndex;
    for (int i = 0; i < nums.size(); i++) {
        valueWithIndex.push_back(make_pair(nums[i], i));
    }

    // Step 2: Sort the vector in descending order of values
    sort(valueWithIndex.begin(), valueWithIndex.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    // Step 3: Take the top k elements with the highest values
    vector<pair<int, int>> topKElements;
    for (int i = 0; i < k; i++) {
        topKElements.push_back(valueWithIndex[i]);
    }

    // Step 4: Sort these k elements based on their original indices
    sort(topKElements.begin(), topKElements.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    // Step 5: Extract only the values in the correct order
    vector<int> result;
    for (int i = 0; i < topKElements.size(); i++) {
        result.push_back(topKElements[i].first);
    }

    return result;
}

int main(){

}