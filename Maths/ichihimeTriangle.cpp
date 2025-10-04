#include<iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b+b>c) cout<<b<<" "<<b<<" "<<c<<endl;
        else if(c+c>b) cout<<b<<" "<<c<<" "<<c<<endl;
    }


    return 0;
}