// 📝 Description:
// Given a sorted array of integers arr (which may contain duplicates) and a target value target, return the starting and ending position of the given target value in the array.

// If the target is not found in the array, return {-1, -1}.

// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
// #include <bits/stdc++.h>

using namespace std;

pair<int, int> Occurence(vector<int> arr, int start, int end, int target){
    int mid, first = -1, last = -1;
    int s = start, e = end;
    //For first occurence
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==target){
            
            first = mid;
            e = mid-1;
        }
        else if(arr[mid]>target){
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }

    //For last occurence
    s = start, e = end;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==target){
            last = mid;
            s = mid+1;
            
        }
        else if(arr[mid]>target){
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }
    return {first, last};
}

int main(){
    int size=10, target;
    vector<int> arr(size);
    srand(time(0));
    for(int i = 0;i<size;i++){
        arr[i] = rand() % 5;
    }
    sort(arr.begin(), arr.end());
    cout<<"The actual sorted array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter the target : ";
    cin>>target;


    pair<int, int> result = Occurence(arr, 0, arr.size() - 1, target);
    if (result.first == -1 && result.second == -1) {
        cout << "Target not found in the array." << endl;
    } else {
        cout << "First occurrence of target is at index: " << result.first << endl;
        cout << "Last occurrence of target is at index: " << result.second << endl;
    }

}