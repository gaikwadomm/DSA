#include<iostream>
#include<vector>
using namespace std;

string sortSentence(string s) {
    int n = s.size(), count = 0, index;
    string temp, result;
    vector<string> sortString(10);
    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            index = temp.back() - '0'; // get the digit at the end
            temp.pop_back(); // remove the digit
            sortString[index] = temp;
            temp.clear();
            count++;
        } else {
            temp += s[i];
        }
    }
    // process the last word
    if (!temp.empty()) {
        index = temp.back() - '0';
        temp.pop_back();
        sortString[index] = temp;
        count++;
    }

    for(int i = 1; i <= count; i++) {
        result += sortString[i];
        if(i != count) result += ' ';
    }
    return result;
}


int main(){
    cout<<sortSentence("is2 sentence4 This1 a3");
}
