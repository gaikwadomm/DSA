#include<iostream>
#include<vector>
using namespace std;

void find(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        arr[i] -= 1;
    }

    for(int i=0;i<n;i++){
        int index = arr[i]%n;
        arr[index] += n;
    }

    int repeated, missing;
    for(int i=0;i<n;i++){
        if(arr[i]/n==0){
            missing = i + 1;
        }
        if(arr[i]/n==2){
            repeated = i + 1;
        }
    }

    cout<<"The missing number is "<<missing<<" and the repeated number is "<<repeated<<".";
}

int main(){
    find({4,3,2,1,2,7,6});
}
