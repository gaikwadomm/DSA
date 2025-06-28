#include<iostream>
#include<vector>
using namespace std;

void recusiveMerge(vector<int>& arr, int start, int mid, int end){
    vector<int> temp(end-start+1);
    int left = start;
    int right = mid+1;
    int index = 0;
    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index] = arr[left];
            index++;
            left++;
        }
        else{
            temp[index] = arr[right];
            index++;
            right++;
        }
    }

    //Agar kuch elem bache ho to
    while(left<=mid){
        temp[index] = arr[left];
        index++;
        left++;
    }
    while(right<=end){
        temp[index] = arr[right];
        index++;
        right++;
    }

    //Make change in the actual array
    index = 0;
    while(start<=end){
        arr[start] = temp[index];
        index++;
        start++;
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start==end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    recusiveMerge(arr, start, mid, end);
}

int main(){
    vector<int> arr = {6,4,7,2,9,8,3,5};
    mergeSort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
}