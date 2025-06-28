#include<iostream>
#include<vector>
using namespace std;

int partion(vector<int>& arr, int start, int end){
    int pos = start;
    for(int i=start;i<=end;i++){
        if(arr[i]<=arr[end]){
            swap(arr[pos], arr[i]);
            pos++;
        }
    }
    
    return pos-1;
}

void quickSort(vector<int>& arr, int start, int end){
    if(start>=end){
        return;
    }
    int pivot = partion(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

int main(){
    vector<int> arr = {6,2,5,1,4,2,3};
    quickSort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}