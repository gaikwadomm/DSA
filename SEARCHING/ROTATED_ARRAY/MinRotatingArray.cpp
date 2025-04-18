// 🔍 Problem Title: Find Minimum in Rotated Sorted Array
// 📝 Description:
// Suppose an array of distinct integers arr is sorted in ascending order, and then rotated at some unknown pivot.
// (That is, the array becomes something like [4,5,6,7,0,1,2]).

// Write a function to find the minimum element in the rotated sorted array.
// Your algorithm must run in O(log n) time.

// 🧪 Example 1:
// Input:
// arr = [4, 5, 6, 7, 0, 1, 2]
// Output:
// 0

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MinRotating(vector<int> arr){
    int mid, start = 0, end = arr.size()-1, ans=arr[0];
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]>=arr[0]){   //That means it is left sorted so the min will be at right
            start = mid + 1;
        }
        else {
            ans = arr[mid];
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the arrays : \n";
    for(int i = 0;i<size;i++){
        cout<<"Enter "<<i<<" element : ";
        cin>>arr[i];
    }

    cout<<"The min in the array is "<<MinRotating(arr);
}