#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        deque<int> d;

        for(int i=0;i<n;i++){

            while(!d.empty() && d.front()<i) d.pop_front();

            if((d.empty() && nums[i]==0) || (d.size()%2==0 && nums[i]==0) || (d.size()%2!=0 && nums[i]==1)){
                if(i+k-1>=n) return -1;
                d.push_back(i+k-1);
                ans++;
            }

             
        }

        return ans;
    }
};