#include<iostream>
#include<vector>
using namespace std;

void findBitBin(vector<string>& ans, string& s, int one, int zero, int n){
    if(one < zero) return;
    if(s.size()==n){
        ans.push_back(s);
        return;
    }
    s.push_back('1');
    findBitBin(ans, s, one+1, zero, n);
    s.pop_back();
    
    s.push_back('0');
    findBitBin(ans, s, one, zero+1, n);
    s.pop_back();
} 

int main(){

}