#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int binary(vector<int> arr, int start, int end, int num){
    if(start>end){
        return -1;
    }

    int mid = (start+end)/2;
    if(arr[mid]==num){
        return mid;
    }
    if(arr[mid]>num){
        return binary(arr,start,mid-1,num);
    }
    else if(arr[mid]<num){
       return binary(arr,mid+1,end,num);
    }
}

int binary_search(vector<int> arr, int start, int end, int num){
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==num){
            return mid;
        }
        if(arr[mid]>num){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;

}

int main(){
    int size = 10,n;
    vector<int> arr(size);
    srand(time(0));
    for(int i =0;i<size;i++){
        arr[i] = rand() % 100;
    }

    sort(arr.begin(), arr.end());
    cout<<"The sorted array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter the element to search : ";
    cin>>n;
    int ans = binary_search(arr,0,arr.size()-1,n);
    int recursion_ans = binary(arr,0,arr.size()-1,n);
    if(ans!=-1){
        cout<<"\nThe element is present at "<<ans<<" without using recursion\n";
        cout<<"\nThe element is present at "<<recursion_ans<<" using recursion\n";
    }
    else{
        cout<<"The element is not present in the array...";
    }

}