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

    
    cout<<"The Actaual Array is : ";
    int row_ind,col_ind;
    for(int i=0;i<(row*col);i++){
        row_ind = i/col;
        col_ind = i%col;
        cout<<matrix[row_ind][col_ind]<<" ";
    }
    cout<<"\n";
    cout<<"The wave form is : ";
    for(int j=0;j<col;j++){
        if(j%2==0){
            for(int i=0;i<row;i++){
                cout<<matrix[i][j]<<" ";
            }
        }
        else{
            for(int i=row-1;i>=0;i--){
                cout<<matrix[i][j]<<" ";
            }
        }
    }

}