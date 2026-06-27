#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void SortArr(int arr[], int n){
    swap(arr[0], arr[n]);

    int parent = 0;

    while(true){
        int largest = parent;
        int left = 2*largest + 1;
        int right = 2*largest + 2;

        if(left<n && arr[left]>arr[largest]) largest = left;
        if(right<n && arr[right]>arr[largest]) largest = right;

        if(parent==largest) break;

        swap(arr[parent], arr[largest]);
        parent = largest;
    }
}

void HeapSort(int arr[], int n){
    // Step-1 : Convert arr into Max Heap (T.C : O(n))
    for(int i=(n/2)-1;i>=0;i--){
        int parent = i;
        
        while(true){
            int largest = parent;
            int left = 2*largest + 1;
            int right = 2*largest + 2;

            if(left<n && arr[left]>arr[largest]) largest = left;
            if(right<n && arr[right]>arr[largest]) largest = right;

            if(parent==largest) break;

            swap(arr[parent], arr[largest]);
            parent = largest;
        }
    }

    // Step-2 : Took all the top elements (n.log(n))
    for(int i=n-1;i>=0;i--){
        SortArr(arr, i);
    }
}

void display(int arr[], int n){
    if(n==0){
        cout<<"Arr is Empty.\n";
        return;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

// int main(){
//     int arr[] = {14,15,12,22,17,20,18,24,23,30,19};
//     HeapSort(arr, 11);
//     display(arr, 11);
// }