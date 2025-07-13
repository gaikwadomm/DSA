#include<iostream>
#include<vector>
using namespace std;

int findSumTargetRepetitionAllowed(vector<int> arr, int start, int end, int sum, int target){
    if(sum == target){
        return 1;
    }
    if(start > end || sum>target){
        return 0;
    }
    if(arr[start]==0){
        return 0;
    }
int include = findSumTargetRepetitionAllowed(arr, start, end, sum+arr[start], target);
int exclude = findSumTargetRepetitionAllowed(arr, start+1, end, sum, target);
return include + exclude;
}

int main(){
    vector<int> temp;
    vector<int> arr = {2,3,4,0};
    int n = arr.size();
    int sum = 0;
    int target = 6;

    int ans = findSumTargetRepetitionAllowed(arr, 0, n-1, sum, target);
    cout<<ans;
}