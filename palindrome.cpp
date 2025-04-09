#include<iostream>

using namespace std;

int palindrome(int num){
    int n = num,rem, ans = 0;
    if(num<0){
        return 0;
    }
    while(num){
        rem = num %10;
        num /= 10;
        ans = ans * 10 + rem; 
    }
    if(n == ans){
        return 1;
    }
    return 0;
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    if(palindrome(num)){
        cout<<"It is the palindrome";
    }
    else{
        cout<<"It is not the plaindrome";
    }
    return 0;
}