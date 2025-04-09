#include<iostream>

using namespace std;

// int binary_decimal(string binr){
//     int n = stoi(binr), rem, ans = 0, multi=1;
//     while(n!=0){
//         rem = n%10;
//         n /= 10;
//         ans += rem*multi;
//         multi *= 2;
//     }
//     return ans;
// }

int complement(int num){
    int ans = 0, n=num, rem,multi = 1;
    
    while(n!=0){
        rem = n%2;
        if(rem == 0){
            rem = 1;
        }
        else{
            rem = 0;
        }
        n /= 2;
        ans += rem*multi;
        multi *= 2;
    }
    return ans;
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    
    cout<<"The complement of the number is "<<complement(num);

    return 0;
}