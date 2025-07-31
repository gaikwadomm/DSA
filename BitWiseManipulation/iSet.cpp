#include<iostream>
using namespace std;

int main(){
    int n = 13, i = 2;
    if(n & (1<<i) != 0){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    //OR
    if((n>>i & 1)!=0){
        cout<<endl<<"1";
    } else{
        cout<<endl<<"0";
    }
}