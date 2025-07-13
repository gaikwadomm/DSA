#include<iostream>
#include<vector>
using namespace std;

void permutationOfRepetition(vector<int>& arr, int start, vector<vector<int>>& ans){
    if(start==arr.size()){
        ans.push_back(arr);
        return;
    }
    vector<bool> flag(21, false);
    for(int i=start;i<arr.size();i++){
        int idx = arr[i]+10;
        if(!flag[idx]){
            flag[idx] = true;
            swap(arr[i], arr[start]);
            permutationOfRepetition(arr, start+1, ans);
            swap(arr[i], arr[start]);
        }
    }
}

int main(){
    vector<int> arr = {1,1,2};
    vector<vector<int>> ans;
    vector<int> flag(21,0); //as the arr will contain the number from -10<=num<=10
    permutationOfRepetition(arr, 0, ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
