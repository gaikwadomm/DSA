// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// [12] and [34, 67, 90] Maximum Pages = 191
// [12, 34] and [67, 90] Maximum Pages = 157
// [12, 34, 67] and [90] Maximum Pages = 113.
// Therefore, the minimum of these cases is 113, which is selected as the output.

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int findPages(vector<int> arr, int N, int M){  
//M number of Students in which books to distribute and N is the number of books
    // if(M>N){
    //     return -1;
    // }
    // int mid, start = 0, end=0,page,count,ans;
    // for(int i =0;i<N;i++){
    //     if(start<arr[i]){
    //         start = arr[i];
    //     }
    //     end += arr[i];
    // }

//     while(start<=end){
//         mid = start + (end-start)/2;
//         page=0, count=1;
//         for(int i =0;i<N;i++){
//             page+=arr[i];
//             if(page>mid){
//                 page=arr[i];
//                 count += 1;
//             }
//         }

//         if(count<=M){
//             end=mid-1;
//             ans=mid;
//         }
//         else{
//             start = mid + 1;
//         }
//     }
    if(M>N){
        return -1;
    }
    int mid, ans, page, count, start=arr[0], end=0;
    for(int i=0;i<N;i++){
        if(arr[i]>start){
            start = arr[i];
        }
        end+=arr[i];
    }

    while(start<=end){
        mid = start+(end-start)/2;
        count=1, page=0;
        for(int i=0;i<N;i++){
            page+=arr[i];
            if(page>mid){
                page=arr[i];
                count++;
            }
        }
        if(count<=M){
            ans = mid;
            end = mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {12,34,67,90};
    int m = 2, n=4;
    int ans = findPages(arr,n,m);
    if(ans!=-1){
        cout<<"The answer is "<<ans;
    }
    else{
        cout<<"The answer is not possible...";
    }
    return 0;
}