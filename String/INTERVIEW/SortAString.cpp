#include<iostream>
#include<vector>
using namespace std;

string sortString(string sentence){
    vector<int> count(26,0);
    int index;
    for(char c:sentence){
        index = c - 'a';
        count[index] += 1;
    }
    string ans;
    char c;
    //The time complexity is n 
    for(int i=0;i<26;i++){
        c = 'a'+i;
        for(int j=0;j<count[i];j++){
            ans.push_back(c);
        }
    }

    return ans;
}

int main(){
    string sentence = "aldkfjcdjjjaaaa";
    cout<<"The sorted string is "<<sortString(sentence);
}
