#include<iostream>
#include<cmath>

using namespace std;

int count(int num){
    int n=0;
    while(num!=0){
        n+=1;
        num /= 10;
    }
    return n;
}

int power(int n, int raise){
    int ans=1;
    for(int i=0;i<raise;i++){
        ans *= n;
    }
    return ans;
}

void armstrong(int num){
    int temp=num,num_digit = count(num),ans=0,rem;
    
    while(num!=0){
        rem = num%10;
        //ans += (int)round(pow(rem,num_digit));
        ans += power(rem, num_digit);
        num /= 10;
    }
    if(ans == temp){
        cout<<"The number is the armstrong number";
    }
    else{
        cout<<"The number is not the armstrong number";
    }
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    armstrong(num);
    return 0;
}