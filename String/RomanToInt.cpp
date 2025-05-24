#include<iostream>
using namespace std;

int findNum(char c){
    int n;
    switch(c){
        case 'I': n = 1;
                    break;
        case 'V': n = 5;
                    break;
        case 'X': n = 10;
                    break;
        case 'L': n = 50;
                    break;
        case 'C': n = 100;
                    break;
        case 'D': n = 500;
                    break;
        case 'M': n = 1000;
                    break;
    }
    return n;
}
int romanToInt(string s) {
    int num=0, n = s.size();
    for(int i=0;i<n-1;i++){
        if(findNum(s[i])<(findNum(s[i+1]))){
            num -= findNum(s[i]);
        }
        else{
            num += findNum(s[i]);
        }
    }
    num += findNum(s[n-1]);
    return num;
}

int main(){
    cout<<"The number is "<<romanToInt("III");
}