#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//Using Binary Search Approach O(n logn)
pair <int, int> PairDifferBinary(vector<int> arr, int target){
    int mid, start, end = arr.size()-1;
    for(int i=0;i<arr.size()-1;i++){
        int x = target + arr[i];
        start = i+1, end = arr.size()-1;
        while(start<=end){
            mid = start + (end-start)/2;
            if(arr[mid] == x){
                return {arr[i], x};
            }
            else if(arr[mid] < x){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return {-1,-1};
}

//Using Two pointer approach O(n)
pair <int, int> TwoSum(vector<int> numbers, int target){
    // int start = 0;
    // int end = start + 1;
    // vector<int> ans;
    // while(end<numbers.size()){
    //     int diff = numbers[end]-numbers[start];
    //     if(diff==target){
    //         return {numbers[start], numbers[end]};
    //     }
    //     else if(diff < target){
    //         end++;
    //     }
    //     else{
    //         start++;
    //     }
    // }
    // return {-1,-1};

    int start=0;
    int end = start + 1;

    while(start<end){
        if((numbers[end]-numbers[start])==target){
            return {start, end};
        } else if((numbers[end]-numbers[start])>target){
            start++;
        } else{
            end--;
        }
    }

    return {-1,-1};
}

int main(){
    int size = 10, n;
    vector<int> arr(size);
    srand(time(0));
    for(int i =0;i<size;i++){
        arr[i] = rand() % 100;
    }

    sort(arr.begin(), arr.end());
    cout<<"The actual array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter the differen to keep in between : ";
    cin>>n;
    pair<int, int> ans = PairDifferBinary(arr, n);
    cout<<"The answer is "<<ans.first<<" and "<<ans.second;

    return 0;
}