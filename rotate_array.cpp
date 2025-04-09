#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
using namespace std;

vector<int> rotate_arr(vector<int> arr){
    int length = arr.size();
    cout<<endl<<length<<endl;
    vector<int> ans(length);
    ans[0] = arr[length-1];
    for(int i = 1; i<length; i++){
        ans[i] = arr[i-1];
    }
    return ans;
}

int main(){
    int size=10;
    vector<int> arr(size);
    srand(time(0));
    for(int i = 0; i<size; i++){
        arr[i] = rand() % 100;
    }

    vector<int> rotated = rotate_arr(arr);
    cout<<"The actual array is ";
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"The rotated array is ";
    for(int num:rotated){
        cout<<num<<" ";
    }
}