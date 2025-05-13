#include<iostream>
#include<vector>
using namespace std;

// Your code is a classic implementation of the Staircase Search (also known as Search in a Row and Column Wise Sorted Matrix) and works under the assumption that:

// ✅ Each row is sorted in increasing order, and
// ✅ Each column is sorted in increasing order

// This means:

// Rows are increasing left to right

// Columns are increasing top to bottom

// But the matrix as a whole does not need to be sorted in a single increasing order (like in a flattened binary search case)

//Stair Case Pattern O(row+col)
int findElement(vector<vector<int>> arr, int target){
    int row=arr.size(), col=arr[0].size();
    int i=0, j=col-1;

    while(i<row && j>=0){
        if(arr[i][j]==target){
            return 1;
        }
        else if(arr[i][j]<target){
            i++;
        }
        else{
            j--;
        }
    }
    return 0;
}


int main(){
    int row, col,n, find;
    cout<<"Enter the Size of the Matrix : ";
    cin>>n;

    row = col = n;
    // cout<<"Enter the number of columns : ";
    // cin>>col;

    vector<vector<int>> matrix(row,vector<int>(col));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter Element : ";
            cin>>matrix[i][j];
        }
    }

    cout<<"The Actuall Matrix is : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }

    cout<<"Enter the number to search : ";
    cin>>find;

    if(findElement(matrix,find)){
        cout<<"The Element is present in the matrix\n";
    }
    else{
        cout<<"The Element is not present in the matrix\n";
    }

}