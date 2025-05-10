#include<iostream>
using namespace std;

int main(){
    int arr[4][4] = {5,8,3,9,6,2,8,4,5,3,2,2,2,8,1,9};
    int firstDiagonal=0, secondDiagonal=0;
    int row=4, col=4;
    
    for(int i=0;i<row;i++){
        firstDiagonal+=arr[i][i];
    }

    int i=0,j=col-1;
    while(j>=0){
        secondDiagonal += arr[i][j];
        i++;
        j--;
    }
    cout<<"The sum of the first diagonal is "<<firstDiagonal<<" and the sum of the second diagonal is "<<secondDiagonal;
}