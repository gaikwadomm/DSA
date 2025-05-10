#include<iostream>
using namespace std;

int main(){
    int arr[3][5] = {2,3,4,5,1,2,6,8,4,9,3,2,8,6,7};
    int row = 3, col = 5;
    cout<<"The actual array is : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col/2;j++){
            swap(arr[i][j], arr[i][col-(j+1)]);
        }
    }

    cout<<"The Reversed Array is : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}