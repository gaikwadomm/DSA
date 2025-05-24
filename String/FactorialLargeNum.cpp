#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Method one 
string multiply(string current, int num){
    string ans;
    int n = current.size()-1, carry=0;
    for(int i=n;i>=0;i--){
        int temp = (current[i]-'0')*num + carry;
        carry = temp / 10;
        char c = (temp % 10) + '0';
        ans.push_back(c);
    }
    while(carry){
        ans.push_back((carry % 10) + '0');
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string factorial(int num){
    string ans="1";
    while(num){
        ans = multiply(ans, num);
        num--;
    }
    return ans;
}

//Method 2
//Using vector

vector<int> vectorMultiply(vector<int> current, int num){
    vector<int> ans;
    int n = current.size()-1, carry=0;
    for(int i=n;i>=0;i--){
        int temp = (current[i])*num + carry;
        carry = temp / 10;
        int c = (temp % 10);
        ans.push_back(c);
    }
    while(carry){
        ans.push_back((carry % 10));
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> vectorFactorial(int num){
    vector<int> ans={1};
    while(num!=0){
        ans = vectorMultiply(ans, num);
        num--;
    }
    return ans;
}


int main(){
    // cout<<"The 192 * 15 = "<<multiply("192", 15)<<endl;
    cout<<"The factorial of 5 is "<<factorial(5);
}
