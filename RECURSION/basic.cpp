#include<iostream>
using namespace std;

void wish(int n){
    if(n==0){
        cout<<"Wish You Happy Birthday!"<<endl;
        return;
    }
    else{
        cout<<n<<" to go..."<<endl;
        wish(n-1);
        cout<<"Done with the operation "<<n<<endl;
    }
}

void even(int n){
    if(n==0){
        return;
    }
    if(n%2==0){
        cout<<n<<endl;
        return even(n-2);
    }
    else{
        return even(n-1);
    }
}

void printRec(int n, int a){
    if(n==a){
        cout<<a<<endl;
        return;
    }
    cout<<a<<endl;
    printRec(n, a+1);
    // cout<<a<<endl;
}

void printRecAnotherWay(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    printRecAnotherWay(n-1);
    cout<<n<<endl;
}

void evenAnotherWay(int n){
    if(n < 2){
        return;
    }
    evenAnotherWay(n-1);
    if(n % 2 == 0){
        cout << n << endl;
    }
}

int main(){
    // wish(7);
    evenAnotherWay(20);
    // printRec(10, 1);
    // printRecAnotherWay(10);
}