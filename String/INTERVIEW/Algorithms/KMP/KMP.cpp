#include<iostream>
#include<vector>
using namespace std;

int kmpBF(string s, string pattern){
    int n = s.size(), p = pattern.size();

    bool check;

    for(int i=0;i<=n-p;i++){
        check = true;
        for(int j=0;j<p;j++){
            if(s[i+j]!=pattern[j]){
                // cout<<s[i+j]<<" "<<pattern[j]<<endl;
                check = false;
                break;
            }
        }
        if(check) return i;
    }
    return -1;
}

int kmp(string s, string pattern){
    int n = s.size(), p = pattern.size();
    vector<int> lps(p, 0);
    int pre = 0, suf = 1;

    while(suf<p){
        if(pattern[pre] == pattern[suf]){
            lps[suf]+=1;
            suf++;
            pre++;
        }
        else{
            if(pre == 0){
                lps[suf] = 0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }

    int st = 0, pt = 0, count=0;
    vector<int> ans;
    while(st<=n-p){
        if(s[st] == pattern[pt]){
            count++;
            st++;
            pt++;
            if(count==n){
                ans.push_back(st-p+1);
                count=0;
            }
        }
        else{
            if(pt == 0){
                st++;
                count=0;
            }
            else{
                pt = lps[pt-1];
                count = pt;
            }
        }
    }
    
    return count == n;
}


int main(){
    cout<<"The pattern is present at "<<kmpBF("abcdabad", "abad");
}
