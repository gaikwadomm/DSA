#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

int minOfMax(vector<int> arr, int M){
    int n = arr.size();
    int start = INT_MIN, end = 0, ans;
    for(int i=0;i<n;i++){
        start = max(start, arr[i]);
        end += arr[i];
    }

    while(start<=end){
        int mid = start + (end - start)/2, count = 1, page=0;
        for(int i=0;i<n;i++){
            page+=arr[i];
            if(page>mid){
                count++;
                page = arr[i];
            }
        }

        if(count<=M){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}


int painterPartition(vector<int> arr, int m){
    int n = arr.size();
    int start = INT_MIN, end = 0, ans;
    for(int i=0;i<n;i++){
        start = max(start, arr[i]);
        end += arr[i];
    }
    while(start<=end){
        int mid = start + (end - start)/2, painters=1, timeReq = 0;
        for(int i=0;i<n;i++){
            timeReq+=arr[i];
            if(timeReq>mid){
                painters++;
                timeReq = arr[i];
            }
        }
        if(painters<=m){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    // cout<<minOfMax({12,34,67,90}, 2);
    cout<<painterPartition({5,10,30,20,15}, 2);
}
