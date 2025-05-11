#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    vector<vector<int>> arr;
    vector<vector<int>> matrix(3,vector<int>(4,1));  //2D vector with 
                                                    //3 row and 4 col
                                                   //and 1 as the default val in i
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }

}