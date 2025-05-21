#include<iostream>
#include<vector>
using namespace std;

//Find the largest palindrome from the string given

int longestPalindrome(string s) {
    int n = s.size();
    vector<int> Count(52,0);
    //Count the each number of letters in the string
    for(char c:s){
        //if the letter is lowerCase
        if(int(c)>=97 && int(c)<=122){
            int index = int(c) % 97;
            Count[index] += 1;
        }
        //if the letter is upperCase
        if(int(c)>=65 && int(c)<=90){
            //from the index 26 of the Count the uppercase will start
            int index = (int(c) % 65)+26; 
            Count[index] += 1;
        }
    }
    int ans = 0, extra = 0;
    for(int i=0;i<Count.size();i++){
        if(Count[i]%2==0){
            ans += Count[i];
        }
        else{
            // if(Count[i]!=0){
                ans += Count[i] - 1;
                extra += 1;
            // }
        }
    }
    if(extra>0) return ans+1;
    return ans;
}

int main(){
    // aabccaccbaa is the longest palindrome with lenght 11
    cout<<"The longest palindrome is of size "<<longestPalindrome("aaaabbbacccc");
}

