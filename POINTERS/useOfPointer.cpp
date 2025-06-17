#include<iostream>
#include<vector>
using namespace std;

int main(){
    int *ptr = new int;
    *ptr = 7;
    cout<<*ptr<<endl;

    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int *p = new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<endl;
    }
}
