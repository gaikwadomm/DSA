#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int SearchTarget(vector<int> arr, int target){
    int mid, start = 0, end = arr.size()-1;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>=arr[0]){   //That means it is left sorted so the min will be at right
            if(arr[start]<=target && target<=arr[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        else {
            if(arr[mid]<=target && target<=arr[end]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
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