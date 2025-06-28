#include<iostream>
#include<type_traits>
#include<climits>
using namespace std;

void printArr(int *ptr, int size, int index = 0){
    if(index>=size) return;
    // cout<<ptr[index]<<endl;
    printArr(ptr, size, index+1);
    cout<<ptr[index]<<endl;
}

int sumOfElem(int *ptr, int index, int sum=0){
    if(index==-1) return sum;
    sum+=ptr[index];
    return sumOfElem(ptr, index-1, sum);
}

int sumEle(int *ptr, int n,  int index=0){
    if(index == n) return 0;
    return ptr[index]+sumEle(ptr, n, index+1);
}

int minArr(int *ptr, int index, int minVal=INT_MAX){
    if(index==-1) return minVal;
    minVal = min(ptr[index], minVal);
    return minArr(ptr, index-1, minVal);
}

int minArrayElem(int *ptr, int index){
    if(index==0) return ptr[index];
    return min(ptr[index], minArrayElem(ptr, index-1));
} //Similarly can find for the max element in the array...

int main(){
    int arr[5] = {7,2,4,2,6};
    // printArr(arr, 8);
    // cout<<sumOfElem(arr, 7)<<endl;
    // cout<<sumEle(arr, 8);
    cout<<minArr(arr, 4)<<endl;
    cout<<minArrayElem(arr, 4);
}