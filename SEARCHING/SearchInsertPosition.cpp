// 🔍 Problem Title: Search Insert Position
// 📝 Description:
// Given a sorted array of distinct integers arr and a target value target, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// 🧪 Example 2:
// Input:
// arr = [1, 3, 5, 6]
// target = 2

// Output:
// 1

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int SearchInsertPosition(vector<int> arr, int target){
    int mid, start=0, end=arr.size()-1, ans=arr.size();
    // if(target>arr[arr.size()-1]){
    //     return arr.size();
    // }
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int size=10, target;
    vector<int> arr(size);
    srand(time(0));
    for(int i = 0;i<size;i++){
        arr[i] = rand() % 50;
    }
    sort(arr.begin(), arr.end());
    cout<<"The actual sorted array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter the target : ";
    cin>>target;

    cout<<"The answer is "<<SearchInsertPosition(arr,target);
}