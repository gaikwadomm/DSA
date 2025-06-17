#include<iostream>
#include<vector>
using namespace std;

void fun(int **n){
    *n = *n+1;  //this will change the address of p as ptr has address of p 
}

void fun2(int *(&p)){
    *(&p) = *(&p)+1;
}

int main(){
    int n = 10;
    int *p = &n; //p is the pointer pointing to the int type value
    int **ptr = &p; //ptr is the pointer pointing to the pointer and that pointer is pointing to the int type value 
    cout<<p<<endl;
    cout<<ptr<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl; //value store in p
    cout<<**ptr<<endl; //value store in ptr which is the address of p 

    // fun(ptr);
    fun2(p);
    cout<<p<<endl;
    cout<<n;

    int ***ptr3 = &ptr;

}