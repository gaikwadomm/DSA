#include<iostream>

using namespace std;

char small_capital(char x){
    int ch = x;
    return x-32;
    
}

char convert(char x){
    return x-'a'+'A';
}

int main(){
    char ch;
    cout<<"Enter the Character : ";
    cin>>ch;
    cout<<"The converted is "<<small_capital(ch)<<endl;
    cout<<"The second convertsion is "<<convert(ch);
    return 0;
}