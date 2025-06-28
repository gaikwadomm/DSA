#include<iostream>
using namespace std;

int powOfTwo(int num,int n){
    if(n==0){
        return 1;
        }
    return num*powOfTwo(num,n-1); 
}

int main(){
    // cout<<powOfTwo(5);
    int n=-1, num=2;
    if(n>=0){
        cout<<powOfTwo(num,n);
    }
    else{
        float ans = 1.0f / powOfTwo(num,abs(n));
        cout<<ans;
    }
}