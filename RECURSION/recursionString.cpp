#include<iostream>
#include<cctype>
using namespace std;

bool checkPalindrome(string s, int start, int end){
    if(s[start]!=s[end]) return 0;
    if(start>=end) return 1;
    return checkPalindrome(s, start+1, end-1);
}
bool isPalindrome(string s) {
    string newS="";
    for(char c:s){
        if(isalnum(c)){
            newS.push_back(c);
        }
    }
    cout<<newS<<endl;
    if(newS.empty()) return true;
    return checkPalindrome(newS, 0, newS.size()-1);
}

int countVowels(string s, int index,int count=0){
    if(index == -1) return count;
    string vowel = "aeiou";
    for(char c:vowel) if(s[index]==c) count+=1;
    return countVowels(s, index-1, count);
}

int countVowelsNewWay(string s, int index){
    if(index == -1) return 0;
    string vowel = "aeiou";
    for(char c : vowel) {
        if(s[index] == c) {
            return 1 + countVowelsNewWay(s, index-1);
        }
    }
    return countVowelsNewWay(s, index-1);
}

void reverseString(string& s, int start, int end){
    if(start>=end){
        return;
    }
    swap(s[start],s[end]);
    reverseString(s,start+1,end-1);
}

void lowerToUpper(string& s, int index){
    if(index == -1){
        return;
    }
    if((int)s[index]>=97){
        s[index] = (int)s[index]-32;
    }
    lowerToUpper(s,index-1);
}

int main(){ 
    // cout<<checkPalindrome("aba", 0, 2)<<endl;
    // cout<<isPalindrome("0P");
    string s = "asddGkaeioua";
    // cout<<countVowels(s, s.size()-1)<<endl;
    // cout<<countVowelsNewWay(s, s.size()-1);
    // reverseString(s, 0, 3);
    // cout<<"The reverse string is "<<s;
    lowerToUpper(s, s.size()-1);
    cout<<s;
}