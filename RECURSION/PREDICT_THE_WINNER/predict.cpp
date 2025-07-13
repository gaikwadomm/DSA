#include<iostream>
#include<vector>
using namespace std;

int winner(vector<int>& person, int n, int index, int person_left, int k){
    if(person_left==1){
        for(int i=0;i<n;i++){
            if(person[i]==0){
                return i;
            }
        }
    }
    int kill = (k-1)%person_left;
    while(kill--){
        index = (index+1) % n;
        while(person[index]==1){
            index = (index+1) % n;
        }
    }
    person[index] = 1;

    while(person[index]==1){
        index = (index+1) % n;
    }
    return winner(person, n, index, person_left-1, k);
}

int moreOptimizedWinner(int n, int k){
    if(n==1){
        return 0;
    }
    return (moreOptimizedWinner(n-1,k)+k)%n;
}

int main(){
    int n = 5, k = 2;
    vector<int> person(n, 0); // Initialize with n zeros
    int person_left = n;
    cout<<"The winner is "<<winner(person, n, 0, person_left, k)<<endl;
    cout<<"The winner by T.C O(n) is "<<moreOptimizedWinner(n,k);
}
