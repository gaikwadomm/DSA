#include<iostream>
#include<vector>
using namespace std;

//O(N)TC and O(N)SC
string sortVowels(string sent){
    int n = sent.size();
    vector<int> vowelLower(26,0);
    vector<int> vowelUpper(26,0);

    //1. Select the vowels and sort the vowels
    for(char &c:sent){
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            int index = (int)c % 65;
            vowelUpper[index] += 1;
            c='#';
        }
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            int index = (int)c % 97;
            vowelLower[index] += 1;
            c='#';
        }
    }


    //2. Insert the vowels at the right 
    string ans;
    for(int i=0;i<26;i++){
        char c = 'A' + i;
        while(vowelUpper[i]){
            ans += c;
            vowelUpper[i]--;
        }
    }
    for(int i=0;i<26;i++){
        char c = 'a' + i;
        while(vowelLower[i]){
            ans += c;
            vowelLower[i]--;
        }
    }
    int v = 0;
    for(char &c:sent){
        if(c=='#'){
            c=ans[v];
            v++;
        }
    }

    return sent;

}

int main(){
    cout<<"The sorted vowels string is "<<sortVowels("lEetcOde");
}
