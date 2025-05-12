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

    //First flip the matrix (i.e first row into last row, second row into second last row and so on )

    int x;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            x=(n-1)-i;
            swap(matrix[i][j], matrix[x][j]);
        }
    }

    //Now reverse the flip matrix
    int y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            y=(n-1)-j;
            swap(matrix[i][j], matrix[i][y]);
        }
    }

    cout<<"The Rotated Matrix by 180 with the Optimal Way (Without creating extra space for the ans ) is \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
}