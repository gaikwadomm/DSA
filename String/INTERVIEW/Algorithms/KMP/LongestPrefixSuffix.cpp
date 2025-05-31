#include<iostream>
#include<vector>
using namespace std;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//Lets solve using the concept of KMP 

int lpsAns(string s){
    int n = s.size();
    vector<int> lps(n, 0);
    int pre = 0, suf = 1;
    
    while(suf<n){
        if(s[pre] == s[suf]){
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else{
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }

    return lps[n-1];
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//The below two code is not good for all the cases 
// int optimalLongestPS(string s){
//     int n = s.size(), prefix = 0, suffix = s.size()-1, maxi = 0;
//     char temp;
//     while(suffix<n && suffix>0){
//         temp = s[prefix];
//         if(s[prefix] != s[suffix]){
//             prefix = 0;
//             maxi = 0;
//             suffix--;
//         }
//         else{
//             prefix++;
//             suffix++;
//             maxi += 1;
//         }
//     }
//     return maxi;
// }

// int longestPrefixSuffixBrute(string s){
//     int n = s.size(), mini = 0;
//     vector<string> prefix;
//     vector<string> suffix;

//     for(int i=0;i<n-1;i++){
//         string temp = "";
//         for(int j=0;j<=i;j++){
//             temp.push_back(s[j]);
//         }
//         prefix.push_back(temp);
//     }

//     for(int i=n-1;i>0;i--){
//         string temp = "";
//         for(int j=i;j<n;j++){
//             temp.push_back(s[j]);
//         }
//         suffix.push_back(temp);
//     }

//     for(int i=0;i<n-1;i++){
//         // cout<<endl<<prefix[i];
//         for(int j=0;j<n-1;j++){
//             // cout<<endl<<suffix[j];
//             if(prefix[i]==suffix[j]){
//                 int t = prefix[i].size();
//                 mini = max(mini, t);
//             }
//         }
//     }

//     return mini;
// }



int main(){
    // cout<<"The answer is "<<longestPrefixSuffixBrute("ABCDEABCD");
    // cout<<"The optimal answer is "<<optimalLongestPS("AAAAAD");
}
