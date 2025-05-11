#include<iostream>
#include<vector>
using namespace std;

int main(){
    int row, col;
    cout<<"Enter the number of rows : ";
    cin>>row;
    cout<<"Enter the number of columns : ";
    cin>>col;

    vector<vector<int>> matrix(row,vector<int>(col));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter Element : ";
            cin>>matrix[i][j];
        }
    }

    int top = 0, right = col-1, bottom = row-1, left = 0;
    cout<<"The Transpose Form of the Matrix is : \n";

    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }
    
    //ALTERNATIVE
    // for(int i=0;i<row-1;i++){
    //     for(int j=i+1;j<col;j++){
    //         if(i!=j){
    //                 swap(mat[i][j], mat[j][i]);
    //         }
    //     }
    // }
}