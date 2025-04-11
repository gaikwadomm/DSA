#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int KthMissing(vector<int> arr, int kth){
    int mid, start = 0, end = arr.size() - 1, ans;
    // int ans = arr[end] + (kth-(arr[end]-end-1));
    if(kth>(arr[end]-end-1)){
        return arr[end] + (kth-(arr[end]-end-1));
        //return ans;
    }
    while(start<=end){
        mid = start + (end -start)/2;
        if((arr[mid]-mid-1)>=kth){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    } 

    return(ans + kth);
}

int main(){
    // int size = 10, kth; // Change as needed
    // vector<int> pool(100);
    
    // // Fill with numbers 0 to 99
    // for (int i = 0; i < 100; ++i) {
    //     pool[i] = i;
    // }

    // // Shuffle the pool
    // srand(time(0));
    // random_shuffle(pool.begin(), pool.end());

    // // Take the first 'size' elements
    // vector<int> arr(pool.begin(), pool.begin() + size);

    // // Optional: sort it
    // sort(arr.begin(), arr.end());

    // cout<<"The actual sorted array is ";
    // for(int i = 0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }
    int kth;
    vector<int> arr = {2,3,4,7,11,12};
    cout<<"The array is ";
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnter the kth missing position to find : ";
    cin>>kth;

    cout<<"\nThe "<<kth<<"th missing element is "<<KthMissing(arr,kth);
}