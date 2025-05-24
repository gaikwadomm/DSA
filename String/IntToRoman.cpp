#include<iostream>
#include<vector>
using namespace std;
 
string intToRoman(int num){
     vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                    tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                    hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                    thousands = {"", "M", "MM", "MMM"};
    string roman = thousands[num/1000] + hundreds[(num%1000)/100] +tens[(num%100)/10] + ones[num%10];
    return roman;
}

int main(){
    cout<<"The roman letter of 50 is "<<intToRoman(50);
}
