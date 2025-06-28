#include<iostream>
#include<vector>
using namespace std;

void paranthesis(int n, int left, int right, vector<string>& ans, string& temp){
    if(left < right){
        return;
    }
    if(left == n && right == n){
        ans.push_back(temp);
        return;
    }
    if(left < n){
        temp.push_back('(');
        paranthesis(n, left+1, right, ans, temp);
        temp.pop_back();
    }
    if(right < left){
        temp.push_back(')');
        paranthesis(n, left, right+1, ans, temp);
        temp.pop_back();
    }
}

int main(){
    int n = 3;
    vector<string> ans;
    string temp;
    int l = 0, r = 0;
    paranthesis(n, l, r, ans, temp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}