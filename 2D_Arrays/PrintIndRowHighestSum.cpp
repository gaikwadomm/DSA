#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[5][4] = {3,4,7,8,2,8,3,9,5,4,2,2,7,3,0,8,2,8,9,1};
    int sum = 0, max=INT_MIN,index;


    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        if(sum>max){
            max = sum;
            index=i;
        }
        sum=0;
    }
    cout<<"The max sum of the row is "<<max<<" and the index of the row is "<<index;
}