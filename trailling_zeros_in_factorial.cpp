#include<iostream>
using namespace std;

// int factorial(int num){
//     if(num==0){
//         return 1;
//     }
//     return num*factorial(num-1);
// }

// void trailling_zeros(int num){
//     int fact = factorial(num),ans=0;
//     if(fact%10!=0){
//         cout<<fact;
//         cout<<"There are 0 trailling zeros.";
//         return;
//     }
//     while(fact%10==0){
//         ans++;
//         fact /= 10;
//     }
//     cout<<"There are "<<ans<<" trailling zeros.";
// }

void trailling_zeros(int num){
    int count = 0;

    if(num<5){
        cout<<"The number of trailling zeros is 0";
        return;
    }

    while(num>=5){
        count += num/5;
        num /= 5;
    }
    cout<<"The number of trailling zeros is "<<count;
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    trailling_zeros(num);
}