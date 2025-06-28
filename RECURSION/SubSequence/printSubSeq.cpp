#include<iostream>
#include<vector>
using namespace std;

void subSeq(vector<int>& arr, int start, int end, vector<vector<int>>&ans, vector<int>& temp){
    if(start==arr.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[start]);
    subSeq(arr, start+1, end, ans, temp);
    temp.pop_back();
    subSeq(arr, start+1, end, ans, temp);
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    subSeq(arr, 0, arr.size()-1, ans, temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){ 
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}