// 🔍 Problem Title: Square Root using Binary Search
// 📝 Description:
// Given a non-negative integer target, return the integer part of its square root.

// In other words, return the greatest integer x such that x * x <= target.

// You must implement a solution with O(log n) time complexity using binary search.

// 🧪 Example 2:
// Input:
// target = 8

// Output:
// Edit
// 2

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int SqrtBS(int target){
    int mid, start = 0, end = target, ans;
    if(target<0){
        return -1;
    }
    if(target==0 || target == 1){
        return target;
    }
    while(start<=end){
        mid = start + (end - start)/2;
        if(mid==target/mid){
            return mid;
        }
        else if(mid<target/mid){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
int main(){
    int size=10, target;
    // vector<int> arr(size);
    // srand(time(0));
    // for(int i = 0;i<size;i++){
    //     arr[i] = rand() % 50;
    // }
    // sort(arr.begin(), arr.end());
    // cout<<"The actual sorted array is ";
    // for(int i = 0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }

    cout<<"\nEnter the target : ";
    cin>>target;
    int ans = SqrtBS(target);
    if(ans != -1){
        cout<<"The sqrt is "<<SqrtBS(target);
    }
    else{
        cout<<"The sqrt does not exists";
    }
}