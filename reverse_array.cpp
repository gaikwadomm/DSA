#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

int main(){
    srand(time(0));
    int size=9;
    int arr[size];

    for(int i=0;i<size;i++){
        arr[i]=rand() % 100;
    }

    cout<<"The array is ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //First method to reverse the array
    // int i = size-1, j = 0;
    // int reverse[size];
    // while(i>=0){
    //     reverse[j] = arr[i];
    //     i--;
    //     j++;
    // }
    // cout<<"The Reverse array is ";

    // for (i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    

    //Another method to do it 
    int i=0,j=size-1;
    int temp;
    while(i<j/2){
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }

    cout<<"The Reverse array is ";

    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}