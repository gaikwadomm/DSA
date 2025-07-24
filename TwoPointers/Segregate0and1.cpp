#include<iostream>
#include<vector>
using namespace std;

vector<int> Segregate(vector<int> arr){
    int start = 0, end = arr.size()-1;
    while(start<end){
        if(arr[start]==0){
            start++;
        }
        else{
            if(arr[end]==1){
                end--;
            }
            else{
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
        }
    }

    //while(start<end){
    //     if(arr[start]==1 && arr[end]==0){
    //         swap(arr[start], arr[end]);
    //     } else if(arr[start]==1){
    //         end--;
    //     } else{
    //         start++;
    //     }
    // }
    return arr;
}

int main(){
    vector<int> arr = {0,1,1,0,1,0,1,0,1,0,0};
    vector<int> ans = Segregate(arr);
    cout<<"The segregated array is ";
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
