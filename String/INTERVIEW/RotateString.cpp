#include<iostream>
using namespace std;

string clockWise(string str1, int times){
    int n = str1.size();
    char c = str1[n-1];
    int index;
    for(int i=0;i<times;i++){
        index = n-1;
        //rotate the string one time clockwise
        while(index>0){
            str1[index] = str1[index-1];
            index--;
        }
        str1[index] = c;
        c = str1[n-1];
    }
    return str1;
}

string antiClockWise(string str1, int times){
    int n = str1.size();
    char c = str1[0];
    int index;
    for(int i=0;i<times;i++){
        index = 0;
        while(index<n-1){
            str1[index] = str1[index+1];
            index++;
        }
        str1[index] = c;
        c = str1[0];
    }
    return str1;
}

int main(){
    cout<<clockWise("amazon",2);
    cout<<endl<<antiClockWise("amazon", 2);
}