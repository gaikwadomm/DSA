#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
using namespace std;

vector<int> selection_sort(vector<int> arr){
    int length = arr.size(), small,temp;
    vector<int> ans = arr;
    for(int i=0;i<length-1;i++){
        small=i;
        for(int j=i+1;j<length;j++){
            if(ans[j]<ans[small]){
                small=j;
            }
        }
        temp = ans[small];
        ans[small]=ans[i];
        ans[i]=temp;
        // ans[small],ans[i] = ans[i],ans[small];
    }

    return ans;
}

int main(){
    int size = 10;
    vector<int> arr(size);
    srand(time(0));
    for(int i = 0;i<size;i++){
        arr[i] = rand() % 100;
    } 

    cout<<"The actual array is ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    vector<int> sorted_array = selection_sort(arr);
    cout<<"\nThe sorted array is ";
    for(int i=0;i<size;i++){
        cout<<sorted_array[i]<<" ";
    }

    return 0;
}