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
    cout<<"The Spiral Form of the Matrix is : ";

    //Time Complexity is O(Row*Col)
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
            cout<<matrix[top][j]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<matrix[i][right]<<" ";
        }
        right--;
        if(top<=bottom){    //Agar upar vala jo top++ hai uske bad 
                           //top<=bottom na raha to vo check karne ke liye
                          //Example array of 1 row and let say 4 columns
                          //In that let 1 2 3 4 
                          //Because if there is no if condition 
                          //than the output will be 1 2 3 4 3 2 1 which is wrong
            for(int j=right;j>=left;j--){
                cout<<matrix[bottom][j]<<" ";
            }
            bottom--;
        }
        if(left<=right){    //Agar upar vala jo right-- hai uske bad 
                           //left<=right na raha to vo check karne ke liye
                          //Example array of 4 row and let say 1columns
                          //In that let 1 2 3 4 
                          //If there is no if condition 
                          //than the output will be 1 2 3 4 3 2 which is wrong
            for(int i=bottom;i>=top;i--){
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }
    }

}