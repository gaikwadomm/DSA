#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<int> temp;
        vector<int> ans(arr.size(), -1);
        
        for(int i=0;i<arr.size();i++){
            while(!temp.empty() && arr[temp.top()] < arr[i]){
                ans[temp.top()] = arr[i];
                temp.pop();
            }
            temp.push(i);
            
        }
        
        return ans;
    }
};