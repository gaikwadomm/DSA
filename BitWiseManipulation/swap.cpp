#include<iostream>
using namespace std;

int main(){
    int a = 10, b = 20;
    cout<<"a : "<<a<<" b : "<<b<<endl;
    a = a ^ b;
    b = a ^ b; //b = a^b = (a^b)^b = a
    a = a ^ b;//a = (a ^ b) ^ a = b
    cout<<"a : "<<a<<" b : "<<b<<endl;
}