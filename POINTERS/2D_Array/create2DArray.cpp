#include<iostream>
using namespace std;

void twoDArray(int rows, int cols){
    int **ptr = new int *[rows];
    for(int i=0;i<rows;i++){
        ptr[i] = new int[cols];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"Enter the Number : ";
            cin>>*(ptr[i]+j);
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<*(ptr[i]+j)<<endl;
        }
    }
    //OR
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<ptr[i][j]<<endl;
        }
    }

    for(int i = 0; i < rows; i++) {
        delete[] ptr[i];  // delete each row (int array)
    }
    delete[] ptr;  // delete the array of int pointers
}

void threeDArray(int x, int rows, int cols){
    int ***ptr = new int **[x];
    for(int i=0;i<x;i++){
        ptr[i] = new int *[rows];
        for(int j=0;j<rows;j++){
            ptr[i][j] = new int[cols];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                cout<<"Enter elements of "<<i+1<<" 2D matrix : ";
                // cin>>*(*(*(ptr+i)+j)+k); OR DIRECTLY
                cin>>ptr[i][j][k];
            }
        }
    }
    for(int i=0;i<x;i++){
        cout<<i+1<<".Matrix : \n";
        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                cout<<ptr[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<rows;j++){
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main(){
    // int cols,rows;
    // cout<<"Enter the number of cols : ";
    // cin>>cols;
    // cout<<"Enter the number of rows : ";
    // cin>>rows;
    // twoDArray(rows, cols);

    int n, rows, cols;
    cout<<"Enter the number of 2D Matrix to store : ";
    cin>>n;
    cout<<"Enter the Number of rows in it : ";
    cin>>rows;
    cout<<"Enter the Number of cols in it : ";
    cin>>cols;
    threeDArray(n, rows, cols);
    return 0;
}
