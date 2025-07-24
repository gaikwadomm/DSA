#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int maxDiff(vector<int> arr){
    int n = arr.size(), SuffixMaxi = INT_MIN, ans=INT_MIN;
    for(int i=n-1;i>0;i--){
        if(arr[i]>SuffixMaxi){
            SuffixMaxi = arr[i];
        }
        ans = max(abs(arr[i-1]-SuffixMaxi), ans);
    }
    return ans;
}

int main(){
    cout<<"\nThe max difference between two elements is "<<maxDiff({9,5,8,12,2,3,7,4});
}
