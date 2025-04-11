#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MinRotating(vector<int> arr){
    int mid, start = 0, end = arr.size()-1, ans=arr[0];
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]>=arr[0]){   //That means it is left sorted so the min will be at right
            start = mid + 1;
        }
        else {
            ans = arr[mid];
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the arrays : \n";
    for(int i = 0;i<size;i++){
        cout<<"Enter "<<i<<" element : ";
        cin>>arr[i];
    }

    cout<<"The min in the array is "<<MinRotating(arr);
}