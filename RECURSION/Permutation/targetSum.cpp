#include<iostream>
#include<vector>
using namespace std;

int targetSumCount(vector<int>& arr, int sum){

    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }

    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans+=targetSumCount(arr, sum-arr[i]);
    }

    return ans;
}

int main(){
    vector<int> arr = {1,5,6};
    int ans = targetSumCount(arr, 7);
    cout<<ans;
}
