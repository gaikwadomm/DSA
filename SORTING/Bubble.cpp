#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<vector>
using namespace std;

vector<int> Bubble_sort(vector<int> arr){
    // vector<int> sorted = arr;
    // int size = sorted.size();
    // bool swapping = false;

    // for(int i = 0; i<size-1; i++){
    //     // cout<<endl<<i<<" array is ";
    //     // for(int j = 0;j<size;j++){
    //     //     cout<<sorted[j]<<" ";
    //     // }
    //     for(int j = 0;j<size-(i+1);j++){
    //         if(sorted[j+1]<sorted[j]){
    //             swapping = true;
    //             swap(sorted[j+1],sorted[j]);
    //         }
    //     }
    //     if(!swapping){
    //         // cout<<"\nThe array is already sorted...";
    //         break;
    //     }
    //     swapping = false;
    // }

    // return sorted;

    int length = arr.size();
    bool swaped = false;
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-(i+1);j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped){
            break;
        }
        swaped = false;
    }
    return arr;
}

int main(){
    int size = 10;
    vector<int> arr(size);
    srand(time(0));
    for(int i = 0; i<size; i++){
        arr[i] = rand() % 100;
    }

    cout<<"The actual array is ";
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    vector<int> sorted_array = Bubble_sort(arr);

    cout<<"\nThe sorted array is ";
    for(int i = 0; i<size; i++){
        cout<<sorted_array[i]<<" ";
    }

    return 0;
}