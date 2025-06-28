#include<iostream>
#include<vector>
using namespace std;

int findSumTarget(vector<int> arr, int start, int end, int sum, int target){
    if(start > end){
        if(sum == target){
            return 1;
        }
        return 0;
    }
int include = findSumTarget(arr, start+1, end, sum+arr[start], target);
int exclude = findSumTarget(arr, start+1, end, sum, target);
return include + exclude;
}

int main(){
    vector<int> temp;
    vector<int> arr = {3,6,4,5,6};
    int n = arr.size();
    int sum = 0;
    int target = 12;

    int ans = findSumTarget(arr, 0, n-1, sum, target);
    cout<<ans;
}