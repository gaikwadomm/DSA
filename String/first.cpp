#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;


//the problem with this is that
//we have to give the max len of the arr
//if we put the very large len 
//and allocate that large memory 
//than it of no use if the arr inputed 
//is small
//example if allocated 1000 
//and arr input is of only 4 than 
//996 will be weasted 
//so to solve this we use string
//which stores the dynamically
//see about this in second.cpp

int main(){
    char arr[20];
    cout<<"Enter the name : ";
    cin>>arr;
    arr[2]='\0';
    cout<<arr<<"\n";  //will print om only if omgaikwad is the input 
                        //as there is the null character at index 2
                        //so it will stop there
    //At the end of the char array there will be the 
    //null character to indicate the stopage of the array
}
