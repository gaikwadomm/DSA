#include<iostream>
#include<vector>
using namespace std;

vector<int> find_fibanoci(int n){
    vector<int> arr(n);
    if (n>0) arr[0]=0;
    if (n>1) arr[1]=1;
    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr;
}

int main(){
    int n;
    cout<<"Enter the Number : ";
    cin>>n;
    vector<int> fib = find_fibanoci(n);
    cout<<"The series is ";
    for(int num:fib){
        cout<<num<<" ";
    }
    
}