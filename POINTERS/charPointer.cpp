#include<iostream>
using namespace std;


int main(){
    char c[] = "gate2024";
    char *p = c;
    cout<<p+c[3]-c[1];
    //i.e address + 'e' - 'a' = address + 4 = 100 + 4 = 104
    //let assume address of starting char g is 100
    //therefor output is 2024 as cout turns address of char into its value 
    //and goes till \0
}