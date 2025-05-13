#include<iostream>
#include<vector>
using namespace std;

//Using BS O(log(n*m))
int findElement(vector<vector<int>> arr, int target){
    int row=arr.size(), col=arr[0].size();
    // index = (i*col)+j;
    int start = 0, end = ((row-1)*col)+(col-1), mid;

    while(start<=end){
        mid = start + (end-start)/2;
        int r=mid/col, c=mid%col;
        if(arr[r][c]==target){
            return 1;
        }
        else if(arr[r][c]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return 0;
}

//Using different approch of BS  O(row+log(col))
int findElem(vector<vector<int>> arr, int target){
    int row = arr.size(), col = arr[0].size(), start, end, mid;
    for(int i=0;i<row;i++){
        if(arr[i][0]<=target && arr[i][col-1]>=target){
            start=0, end = col-1;
            while(start<=end){
                mid = (start+end)/2;
                if(arr[i][mid]==target){
                    return 1;
                }
                else if(arr[i][mid]>target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
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

    if(findElem(matrix,find)){
        cout<<"The Element is present in the matrix (using different kind of BS approch)";
    }
    else{
        cout<<"The Element is not present in the matrix (using different kind of BS approch)";
    }

}