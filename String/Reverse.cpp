#include<iostream>
using namespace std;

int main(){
    string name = "dawkiag mo\n";
    int i=0, j=name.size()-1;
    while(i<name.size()/2){
        swap(name[i],name[j]);
        i++;
        j--;
    }
    int size = 0;
    while(name[size+1]!='\0'){
        size++;
    }
    cout<<name;
    cout<<" The size of the string is "<<size+1;

    string pal = "ABCCBA";
    int start = 0, end = pal.size()-1;
    while(start<end){
        if(pal[start]!=pal[end]){
            cout<<endl<<pal<<" is Not a palindrome";
            return 0;
        }
        start++;
        end--;
    }
    cout<<endl<<pal<<" is the palindrome";
}   
