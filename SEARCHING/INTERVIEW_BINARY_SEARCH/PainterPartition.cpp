// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

// Return the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered [2,3,4] or only board [1] or nothing but not boards [2,4,5].

// Examples:

// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20,15], Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int minPaintTime(vector<int> arr, int painter){
    int mid, start = 0, end = 0, size = arr.size(), timetaken, num_painter, ans;
    for(int i = 0; i < size; i++){
        if(end<arr[i]){
            start = arr[i];
        }
        end += arr[i];
    }
    while(start<=end){
        mid = start + (end-start)/2;
        timetaken=0, num_painter=1;
        for(int i =0;i<size;i++){
            timetaken += arr[i];
            if(timetaken>mid){
                timetaken = arr[i];
                num_painter += 1;
            }
        }
        if(num_painter<=painter){
            end = mid-1;
            ans = mid;
        }
        else{
            start = mid + 1; 
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {5,10,30,20,15};
    int m = 2;
    int ans = minPaintTime(arr, m);
    if(ans!=-1){
        cout<<"The min time require to color the wall is "<<ans;
    }
    else{
        cout<<"The answer is not possible...";
    }
    return 0;
}

