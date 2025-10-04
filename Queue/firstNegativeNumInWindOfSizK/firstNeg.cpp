#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        if (k == 0 || k > n) return ans;
    
        queue<int> q; // store indices of negative numbers
        
        for(int i=0;i<k-1;i++) if(arr[i]<0) q.push(i);
        
        for(int i=k-1;i<n;i++){
            if(arr[i]<0) q.push(i);
            
            if(q.empty()){
                ans.push_back(0);
            } else{
                if(q.front()<=i-k) q.pop();
                
                if(q.empty()) ans.push_back(0);
                else ans.push_back(arr[q.front()]);
            }
        }
        
        return ans;
    }
};