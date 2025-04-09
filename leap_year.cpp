#include<iostream>

using namespace std;

void leap_year(int year){
    if(year % 400 == 0){
        cout<<"The Year is the leap year...";
    }
    else{
        if(year % 4 == 0 && year % 100 != 0){
            cout<<"The Year is the leap year...";
        }
        else{
            cout<<"The Year is not the leap year...";
        }
    }
}

int main(){
    int year;
    cout<<"Enter the number : ";
    cin>>year;

    leap_year(year);

    return 0;
}