#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    int col=n;
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
}

int main(){
     int row, col,n, deg;
    cout<<"Enter the Size of the Matrix : ";
    cin>>n;
    cout<<"Enter the angle of rotation : ";
    cin>>deg;
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
    int nTimes = deg/90;
    for(int KTime=0;KTime<(nTimes%4);KTime++){
        rotate(matrix);
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