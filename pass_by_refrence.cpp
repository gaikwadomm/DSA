#include<iostream>

using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}

void swap(float &a, float &b){
    float temp;
    temp = a;
    a=b;
    b=temp;
}

int main(){
    int a,b;
    cin>>a>>b;

    swap(a,b);
    cout<<a<<" "<<b<<" ";

    float c,d;
    cin>>c>>d;

    swap(c,d);
    cout<<c<<" "<<d<<" ";
    
    return 0;
}