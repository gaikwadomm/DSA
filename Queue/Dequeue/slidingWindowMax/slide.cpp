#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> d;

        for(int i=0;i<n;i++){
            while(!d.empty() && nums[i]>=nums[d.back()]) d.pop_back();

            while(!d.empty() && d.front()<=i-k) d.pop_front();

            d.push_back(i);

            if(i>=k-1) ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};