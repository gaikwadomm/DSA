#include<iostream>
#include<vector>
using namespace std;

int subSeqSum(vector<int> arr, int start, int end, int sum){
    if(start > end){
        // ans.push_back(temp);
        return sum;
    }

    int include = subSeqSum(arr, start+1, end, sum+arr[start]);
    
    int exclude = subSeqSum(arr, start+1, end, sum);

    return include+exclude;
}

void sumSubSeq(vector<int> arr, int start, int end, int sum){
    if(start == arr.size()){
        cout<<sum<<endl;
        return;
    }
    sumSubSeq(arr, start+1, end, sum+arr[start]);
    sumSubSeq(arr, start+1, end, sum);
}

int main(){
    vector<int> temp;
    vector<int> arr = {3,4,5};
    int n = arr.size();
    int sum = 0;

    int ans = subSeqSum(arr, 0, n-1, sum);
    cout<<ans;
    sumSubSeq(arr, 0, n-1, 0);
}