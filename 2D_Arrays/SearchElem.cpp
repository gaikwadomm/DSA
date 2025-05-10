#include<iostream>
using namespace std;

int main(){
    int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int find;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Enter the element to find : ";
    cin>>find;

    for(int i =0;i<4;i++){
        for(int j =0;j<3;j++){
            if(arr[i][j]==find){
                int index=(i*3)+j;
                cout<<"The element is present at index : "<<index<<"\n";
                cout<<"The address of the element with base address 500 is : "<< (500 + (index*sizeof(int)))<<"\n";
                cout<<"The position in the 2D array is row "<<i<<" and column "<<j<<".";
                return 0;
            }
        }
    }
    cout<<"The element is not present in the array.";
}