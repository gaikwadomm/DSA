#include<iostream>
#include<climits>
using namespace std;

int reverse_int(int num){
    int n=num, rem, ans=0;
    while(n>0){

        rem = n % 10;
        n /= 10;
        ans = ans*10 + rem;
    }
    return ans;
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;

    cout<<"The reverse order of the enter number is "<<reverse_int(num);
    cout<<endl<<INT_MAX;
    return 0;
}