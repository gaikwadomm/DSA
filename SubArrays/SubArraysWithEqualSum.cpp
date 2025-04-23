#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void equalSum(vector<int> arr){
    int totalSum = 0;
    for(int i =0;i<arr.size();i++){
        totalSum+=arr[i];
    }
    int prefix = 0;
    for(int i = 0; i<arr.size()-1;i++){
        prefix+=arr[i];
        int ans = totalSum-prefix;
        if(ans == prefix){
            cout<<"The answer is "<<ans;
            return;
        }
        
    }
    cout<<"There is no two subarrays with equal sum";
}

int main(){
    int size = 4, n;
    vector<int> arr(size);
    srand(time(0));
    for(int i =0;i<size;i++){
        arr[i] = rand() % 100;
    }
    cout<<"The actual array is ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    equalSum({3,4,-2,5,8,20,-10,8});

    // sort(arr.begin(), arr.end());


    // cout<<"\nEnter the differen to keep in between : ";
    // cin>>n;
    // pair<int, int> ans = PairDifferBinary(arr, n);
    // cout<<"The answer is "<<ans.first<<" and "<<ans.second;

    return 0;
}
