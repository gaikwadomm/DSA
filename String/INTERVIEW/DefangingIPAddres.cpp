#include<iostream>
using namespace std;


int main(){
    int index = 0;
    string ans;
    string addrs = "255.100.25.60";
    while(index<addrs.size()){
        if(addrs[index]=='.'){
            ans += "[.]";
        }
        else{
            ans += addrs[index];
        }
        index++;
    }
    cout<<"The answer is "<<ans;
}
