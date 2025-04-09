#include<iostream>
using namespace std;

int sqrt(int num){
    int boundary = num/2;
    for(int i=0;i<=boundary;i++){
        if(i*i == num){
            return i;
        }
        if(i*i>num){
            return i-1;
        }
    }
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    cout<<"The absolute sqrt of the number is "<<sqrt(num);
    return 0;
}