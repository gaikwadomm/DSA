#include<iostream>
using namespace std;

int sum_digit(int num){
    int n=num,sum=0,rem;
    while(n>0){
        rem = n%10;
        sum+=rem;
        n /= 10;
    }
    return sum;
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"The sum of the digits of the number is "<<sum_digit(num);
    
    return 0;
}