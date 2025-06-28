#include<iostream>
using namespace std;

int sumSq(int n){
    if(n==0){
        return 0;
    }
    return (n*n) + sumSq(n-1);
}

int sumSqEase(int n){
    return (n*(n+1)*(2*n+1))/6;
}

int main(){
    cout<<sumSq(4)<<endl;
    cout<<sumSqEase(4);
}