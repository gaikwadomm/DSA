// 🔍 Problem Title: Search in Rotated Sorted Array
// 📝 Description:
// There is an integer array arr sorted in ascending order (with distinct values), which is rotated at an unknown pivot index.

// You are given the array and a target value. Implement a function to search the target in the array.
// If the target exists, return its index. Otherwise, return -1.

// Your algorithm must run in O(log n) time.

// 🧪 Example 1:
// Input:
// arr = [4,5,6,7,0,1,2]
// target = 0
// Output:
// 4

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int SearchTarget(vector<int> arr, int target){
    int mid, start = 0, end = arr.size()-1;
    // while(start<=end){
    //     mid = (start+end)/2;
    //     if(arr[mid]==target){
    //         return mid;
    //     }
    //     else if(arr[mid]>=arr[0]){   //That means it is left sorted so the min will be at right
    //         if(arr[start]<=target && target<=arr[mid]){
    //             end = mid -1;
    //         }
    //         else{
    //             start = mid + 1;
    //         }
    //     }
    //     else {
    //         if(arr[mid]<=target && target<=arr[end]){
    //             start = mid + 1;
    //         }
    //         else{
    //             end = mid - 1;
    //         }
    //     }
    // }


    while(start<=end){
        mid = start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>=arr[0]){
            if(arr[start]<=target && target<=arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(arr[start]<=target && target<=arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    }


    return -1;
}

int main(){
    int size, target;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the arrays : \n";
    for(int i = 0;i<size;i++){
        cout<<"Enter "<<i<<" element : ";
        cin>>arr[i];
    }

    cout<<endl<<"Enter the element to search : ";
    cin>>target;
    int check = SearchTarget(arr, target);
    if(check!=-1){
        cout<<"The element is present at "<<check;
    }
    else{
        cout<<"The given element is not present in the array...";
    }
}