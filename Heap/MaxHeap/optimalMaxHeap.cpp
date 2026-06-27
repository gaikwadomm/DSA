#include<iostream>
using namespace std;

// Solving in O(n)
// Using Step-down Approch (Heapify)
void BuildMaxHeap(int arr[], int n){
    // Step down 
    if(n==0) return;

    int start = (n/2)-1;

    for(int i=start;i>=0;i--){
        int parent = i;

        while(true){
            int left = 2*parent + 1;
            int right = 2*parent + 2;
            int largest = parent;

            if(left<n && arr[left]>arr[largest]) largest = left;
            if(right<n && arr[right]>arr[largest]) largest = right;

            if(largest==parent) break;

            swap(arr[parent], arr[largest]);
            parent = largest;
        }
    }
}

void Heapify(int arr[], int index, int n){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest = right;

    if(largest!=index){
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeapRecursion(int arr[], int n){
    for(int i=(n/2)-1;i>=0;i--){
        Heapify(arr, i, n);
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {10,3,8,9,5,13,18,14,11,70};

    BuildMaxHeap(arr, 10);
    display(arr, 10);
}