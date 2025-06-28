#include <iostream>
#include <unordered_map>
#include <vector>
#include<climits>
using namespace std;

void subSeq(string& arr, int start, int end, unordered_map<string, int>& ans, string& temp){
    if(start==arr.size()){
        ans[temp]+=1;
        return;
    }
    temp.push_back(arr[start]);
    subSeq(arr, start+1, end, ans, temp);
    temp.pop_back();
    subSeq(arr, start+1, end, ans, temp);
}  

string finalAns(unordered_map<string, int>& ans, int k) {
    string temp = "";
    string largestSub = "";

    for (const auto& pair : ans) {
        // If this subsequence appears exactly k times
        if (pair.second == k) {
            // Check if it's longer than the current longest one
            if (pair.first.length() > largestSub.length()) {
                largestSub = pair.first;
            }
        }
    }

    return largestSub;
}


int main() 
{   
    string s = "letsleetcode";
    // string s = "bb";
    int k = 2;
    int n = s.size();
    unordered_map<string, int> ans;
    string temp;
    subSeq(s, 0, n-1, ans, temp);
    // for (const auto& pair : ans) {
    //     cout << pair.first << " : " << pair.second << endl;
    // }
    cout<<finalAns(ans, k);
}