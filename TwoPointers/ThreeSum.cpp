#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int TwoSum(vector<int> arr, int target){
    int n = arr.size();
    int start = 0;
    int end = arr.size()-1;
    while(start<end){
        if(arr[start]+arr[end]==target){
            cout<<arr[start]<<"\n"<<arr[end]<<"\n";
            return 1;
        }
        else if(arr[start]+arr[end]>target){
            end--;
        }
        else{
            start++;
        }
    }
    return 0;
}

int ThreeSum(vector<int> arr, int target){
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i=0;i<n-2;i++){
        vector<int> subVector(arr.begin()+(i+1), arr.end());
        int find = target - arr[i];
        if(TwoSum(subVector, find)){
            cout<<arr[i];
            return 1;
        }
    }
    return 0;
}


int main(){
    if(ThreeSum({1,4,45,6,10,8}, 13)){
        cout<<"The sum of three 13 is present";
    }
    else{
        cout<<"The sum is not present in the array";
    }
}