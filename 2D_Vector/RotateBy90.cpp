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
    vector<vector<int>> ans(row,vector<int>(col));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter Element : ";
            cin>>matrix[i][j];
        }
    }

    //With creating extra space for ans
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int x=(row-1)-i;
            ans[j][x] = matrix[i][j];
        }
    }

    cout<<"The Actuall Matrix is : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }

    cout<<"The Rotated Matrix is : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;   
    }

    /* ++++++++++++++++++++++++++++++++++++++++++++++++++ */

    //Without Creating the extra space for the ans

    //First Find the Transpose of the Matrix
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //Now reverse the rows of the transpose matrix 
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int x=(col-1)-j;
            swap(matrix[i][j], matrix[i][x]);
        }
    }

    cout<<"The Rotated Matrix with the Optimal Way (Without creating extra space for the ans ) is \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
}