#include<iostream>
using namespace std;

int satisfying_power_of_2(int num){
    int n=num;
    if(num<=0 || num%2!=0){
        return 0;
    }

    if(num==1){
        return 1;
    }

    while(n!=1){
        if(n%2 != 0){
            return 0;
        }
        n /= 2;
    }
    return 1;
}

int other_logic(int num){
    int n = num, pow=2;
    if(pow==num){
        return 1;
    }
    if(num<=0){
        return 0;
    }
    if(num%2!=0){
        return 0;
    }
    while(pow<num){
        pow*=2;
        if(pow==num){
            return 1;
        }
    }
    return 0;
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;

    int flag = satisfying_power_of_2(num);
    if(flag){
        cout<<"The number is in power of 2"<<endl;
    }
    else{
        cout<<"The number is not in the power of 2"<<endl;
    }
    int flag2 = other_logic(num);
    if(flag2){
        cout<<"The number is in power of 2"<<endl;
    }
    else{
        cout<<"The number is not in the power of 2"<<endl;
    }
    return 0;
}