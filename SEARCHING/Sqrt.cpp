#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int SqrtBS(int target){
    int mid, start = 0, end = target, ans;
    while(start<=end){
        mid = (start+end)/2;
        if(mid*mid == target){
            return mid;
        }
        else if(mid*mid<target){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int size=10, target;
    // vector<int> arr(size);
    // srand(time(0));
    // for(int i = 0;i<size;i++){
    //     arr[i] = rand() % 50;
    // }
    // sort(arr.begin(), arr.end());
    // cout<<"The actual sorted array is ";
    // for(int i = 0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }

    cout<<"\nEnter the target : ";
    cin>>target;
    vector<int> arr(target);
    for(int i = 0;i<=target;i++){
        arr[i] = i;
    }

    cout<<"The sqrt is "<<SqrtBS(target);

}