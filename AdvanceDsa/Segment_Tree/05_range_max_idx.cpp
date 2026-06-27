#include<bits/stdc++.h>
using namespace std;


void build(int idx, int low, int high, vector<int>& seg, vector<int>& nums){
    if(low==high){
        seg[idx] = low;
        return;
    }

    int mid = low + (high-low)/2;
    build(2*idx+1, low, mid, seg, nums);
    build(2*idx+2, mid+1, high, seg, nums);

    int leftIdx = seg[2*idx+1], rightIdx = seg[2*idx+2];
    if(nums[leftIdx]>nums[rightIdx]){
        seg[idx] = leftIdx;
    }
    else seg[idx] = rightIdx;
}


// will give the index of the max
// in the particular segment
int solve(int idx, int low, int high, int& l, int& r, vector<int>& seg, vector<int>& nums){
    if(low>=l && high<=r){
        return seg[idx];
    }
    if(high<l || low>r) return -1;


    int mid = low + (high-low)/2;
    int leftIdx = solve(2*idx+1, low, mid, l, r, seg, nums);
    int rightIdx = solve(2*idx+2, mid+1, high, l, r, seg, nums);

    if(leftIdx!=-1 && rightIdx!=-1){
        if(nums[leftIdx]>nums[rightIdx]) return leftIdx;
        else return rightIdx;
    }
    else if(leftIdx!=-1) return rightIdx;
    else return leftIdx;
}


int main(){

}