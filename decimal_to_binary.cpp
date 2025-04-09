#include<iostream>

using namespace std;

int decimal_binary(int num){
    int n=num,binary=0,i=0,multi=1,rem;
    
    while(n>0){
        rem = n%2;
        n = n/2;
        binary = rem * multi + binary;
        multi *= 10;
    }

    return binary;
}

int binary_decimal(int binr){
    int n = binr, rem, multi=1, deci=0;
    while(n>0){
        rem = n % 10;
        n /= 10;
        deci += rem*multi;
        multi *= 2;
    }
    return deci;
}

int decimal_octal(int num){
    int n = num, rem, octal=0, multi=1;

    while(n>0){
        rem = n % 8;
        n /= 8;
        octal += rem * multi;
        multi *= 10;
    }

    return octal;
}

int octal_decimal(int oct){
    int n = oct, rem, deci = 0, multi = 1;

    while(n>0){
        rem = n%10;
        n /= 10;
        deci += rem * multi;
        multi *= 8; 
    }

    return deci;
}

int main(){
    int num, bin,num1,oct;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"The binary form of the enter number is "<<decimal_binary(num)<<endl;

    cout<<"Enter the Binary Number: ";
    cin>>bin;
    cout<<"The Decimal form of the enter Binary Number is "<<binary_decimal(bin)<<endl;

    cout<<"Enter the number: ";
    cin>>num1;
    cout<<"The octal form of the enter number is "<<decimal_octal(num1)<<endl;

    cout<<"Enter the Octal Number: ";
    cin>>oct;
    cout<<"The Decimal form of the enter Octal Number is "<<octal_decimal(oct);

    return 0;
}