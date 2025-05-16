//Find that which number from 1 to N 
//Appears how many times 

#include<iostream>
#include<vector>
using namespace std;

void printAppear(vector<int> arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        arr[i]--;
    }

    for(int i=0;i<n;i++){
        int index = arr[i] % n;
        arr[index] += n;  //har index ko jake bata na hai ki tu itne itne bar aya hai
    }

    for(int i=0;i<n;i++){
        arr[i] = arr[i] / n;   //Bhai tu itne bar aya hai
    }

    for(int i=0;i<n;i++){
        cout<<"Number "<<i+1<<" appears "<<arr[i]<<" times.\n";
    }
}

int main(){
    printAppear({3,2,5,3,1,2,3,7});
}

