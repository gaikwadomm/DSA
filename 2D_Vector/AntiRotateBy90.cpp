#include<iostream>
#include<vector>
using namespace std;

int main(){
     int row, col,n;
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

    /* ++++++++++++++++++++++++++++++++++++++++++++++++++ */

    //Without Creating the extra space for the ans

    //First Take the Transpose of the Matrix

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Now Flip the Transpose of the Matrix (i.e first row will be converted into last and second into second last )
    int x;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            x=(n-1)-i;
            swap(matrix[i][j], matrix[x][j]);
        }
    }

    cout<<"The Matrix Rotated Anti Clock Wise with the Optimal Way (Without creating extra space for the ans ) is \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
}