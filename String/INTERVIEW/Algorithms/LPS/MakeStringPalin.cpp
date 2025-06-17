#include<iostream>
#include<vector>
using namespace std;

int palindrome(string pal){
    // ✅ Purpose: Checks whether a given string is a palindrome or not using two pointers.
    int n = pal.size();
    int start = 0, end = n-1;
    while(start<=end){
        if(pal[start]==pal[end]){
            start++;
            end--;
        }
        else{
            return 0;
        }
    }
    return 1;
}


int longestPrefixPalindrome(const string& pal) {
    // ✅ Purpose: Brute-force method to find the longest prefix of the string that is a palindrome.

    // 🔴 Time complexity: O(n²)
    int n = pal.size();
    for (int len = n; len >= 1; len--) {
        int i = 0, j = len - 1;
        bool isPalindrome = true;
        while (i < j) {
            if (pal[i] != pal[j]) {
                isPalindrome = false;
                break;
            }
            i++;
            j--;
        }
        if (isPalindrome) {
            return len;
        }
    }
    return 0; // If no prefix is a palindrome, return 0
}

//Most optimal way for the above function of finding the longest prefix palindrome 
int longestPrefixPalindromeUsingLps(string pal){
    // ✅ Purpose: Uses KMP (Knuth-Morris-Pratt) LPS technique to find the longest prefix of s that is a palindrome.

    // 🔵 Input should be: s + '$' + reverse(s)
    // 📌 Why? So we can compute how much of the original string’s suffix matches the reversed prefix — which helps identify the largest palindromic prefix.

    // 🟢 Time complexity: O(n)
    int n = pal.size();
    vector<int> lps(n,0);
    int pref = 0, suff=1; //at n/2 $ will be there 
    while(suff<n){
        if(pal[pref]==pal[suff]){
            lps[suff] = pref + 1;
            pref++;
            suff++;
        }
        else{
            if(pref==0){
                lps[suff]=0;
                suff++;
            }
            else{
                pref = lps[pref-1];
            }
        }
    }
    
    return lps[n-1];
}

int minChar(string s) {
    // Write your code here
    // int n = s.size();
    // int start = 0, end = n-1, ans = 0;
    // while(end>=0){
    //     if(palindrome(s.substr(0, end+1))){
    //         break;
    //     }
    //     else{
    //         ans++;
    //         end--;
    //     }
    // }
    // return ans;
    
    // int n = s.size();
    // int start = 0, end = n-1;
    // return s.size()-longestPrefixPalindrome(s);
    
    int n = s.size();
    int start = 0, end = n-1;
    string complete = s;
    complete.push_back('$');
    for(int i=n-1;i>=0;i--) complete.push_back(s[i]);
    
    return n - longestPrefixPalindromeUsingLps(complete);
    
}

int main(){
    string s = "roorsp";
    int n = s.size();
    int minToPut = minChar(s);
    cout<<"The char to put to make palindrome are : ";
    for(int i=n-1;i>=n-minToPut;i--) cout<<s[i]<<" "; 
    cout<<"\nThe Min char required to make the given string a plaindrome are "<<minChar("roorsp");
}
