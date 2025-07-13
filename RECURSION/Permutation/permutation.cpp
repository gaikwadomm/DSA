#include<iostream>
#include<vector>
using namespace std;

void permute(vector<int>& arr, int start, vector<vector<int>>& ans){
    if (start == arr.size()) {
        ans.push_back(arr);
        return;
    }
}

void permuteAnotherWay(vector<int>& arr, int start, vector<vector<int>>& ans) {
    if (start == arr.size()) {
        ans.push_back(arr);
        return;
    }
    for (int i = start; i < arr.size(); ++i) {
        // Visual trace: print current state before swap
        cout << "Before swap: ";
        for (int num : arr) cout << num << " ";
        cout << " | Swapping arr[" << start << "] and arr[" << i << "]" << endl;

        swap(arr[start], arr[i]);
        permuteAnotherWay(arr, start + 1, ans);

        // Visual trace: print current state after backtrack
        swap(arr[start], arr[i]); // backtrack
        cout << "After backtrack: ";
        for (int num : arr) cout << num << " ";
        cout << " | Backtracked arr[" << start << "] and arr[" << i << "]" << endl;
    }
}


int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    permuteAnotherWay(arr, 0, ans);
     
}